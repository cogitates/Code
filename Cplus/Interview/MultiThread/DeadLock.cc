// Dead Lock
// https://paul.pub/cpp-concurrency/

#include <bits/stdc++.h>
using namespace std;

class Account {
public:
  Account(string name, double money): mName(name), mMoney(money) {};

public:
  void changeMoney(double amount) {
    mMoney += amount;
  }
  string getName() {
    return mName;
  }
  double getMoney() {
    return mMoney;
  }
  mutex* getLock() {
    return &mMoneyLock;
  }

private:
  string mName;
  double mMoney;
  mutex mMoneyLock;
};

class Bank {
public:
  void addAccount(Account* account) {
    mAccounts.insert(account);
  }
/*
仔细思考一下这两个线程的逻辑：
这两个线程可能会同时获取其中一个账号的锁，然后又想获取另外一个账号的锁，此时就发生了死锁。
*/ 

  bool transferMoney(Account* accountA, Account* accountB, double amount) {
    // lock(*accountA->getLock(), *accountB->getLock());
    /* which will result deadlock
    lock_guard guardA(*accountA->getLock());
    lock_guard guardB(*accountB->getLock());
    */

    /*
    lock(*accountA->getLock(), *accountB->getLock()); // 分别上锁，保证不同时上锁
    lock_guard lockA(*accountA->getLock(), adopt_lock); // adopt_lock起标记作用，表示互斥量已经Lock过
    lock_guard lockB(*accountB->getLock(), adopt_lock);
    */
    scoped_lock lockAll(*accountA->getLock(), *accountB->getLock());

    if (amount > accountA->getMoney()) {
      return false;
    }

    accountA->changeMoney(-amount);
    accountB->changeMoney(amount);
    return true;
  }

  double totalMoney() const {
    double sum = 0;
    for (auto a : mAccounts) {
      sum += a->getMoney();
    }
    return sum;
  }

private:
  set<Account*> mAccounts;
};


mutex sCoutLock;
void randomTransfer(Bank* bank, Account* accountA, Account* accountB) {
  while(true) {
    double randomMoney = ((double)rand() / RAND_MAX) * 100;
    if (bank->transferMoney(accountA, accountB, randomMoney)) {
      sCoutLock.lock();
      cout << "Transfer " << randomMoney << " from " << accountA->getName()
          << " to " << accountB->getName()
          << ", Bank totalMoney: " << bank->totalMoney() << endl;
      sCoutLock.unlock();
    } else {
      sCoutLock.lock();
      cout << "Transfer failed, "
           << accountA->getName() << " has only " << accountA->getMoney() << ", but "
           << randomMoney << " required" << endl;
      sCoutLock.unlock();
    }
  }
}


int main() {
  Account a("Paul", 100);
  Account b("Moira", 100);

  Bank aBank;
  aBank.addAccount(&a);
  aBank.addAccount(&b);

  thread t1(randomTransfer, &aBank, &a, &b);
  thread t2(randomTransfer, &aBank, &b, &a);

  t1.join();
  t2.join();

  return 0;
}