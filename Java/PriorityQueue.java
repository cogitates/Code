import java.util.*;

class PriorityQueue{
    private int[] arr;
    private int size;

    public PriorityQueue(){
        this(64);
    }
    public PriorityQueue(int initSize){
        if(initSize <= 0)
            initSize = 64;
        this.arr = new int[initSize];
        this.size = 0;
    }
    public int max(){
        return this.arr[0];
    }
    public int maxAndRemove(){
        int t = max();
        this.arr[0] = this.arr[--size];
    sink(0,this.arr[0]);
        return t;
    }
    public void add(int data){
        resize(1);
        this.arr[size++] = data;
        pop(size-1,data);
    }

    // 下沉
    private void sink(int i, int key){
        while(2*i <= this.size - 1){
            int child = 2 * i;
            if(child < this.size -1 && this.arr[child] < this.arr[child+1]){
                child++;
            }
            if(this.arr[i] >= this.arr[child]){
                break;
            }
            swap(i,child);
            i = child;
        }
    }

    private void pop(int i, int key){
        while(i > 0){
            int parent = i / 2;
            if(this.arr[i] < this.arr[parent]){
                break;
            }
            swap(i,parent);
            i = parent;
        }
    }
    private void resize(int increaseSize){
        if((this.size + increaseSize) > this.arr.length){
            int newLength = 2 * this.arr.length;
            int[] t = this.arr;
            this.arr = Arrays.copyOf(t, newLength);
        }

    }
    private void swap(int a, int b) {
        int t = this.arr[a];
        this.arr[a] = this.arr[b];
        this.arr[b] = t;
    }

    public static void main(String[] args) {
        PriorityQueue queue = new PriorityQueue();
        queue.add(12);
        queue.add(23);
        queue.add(1);
        queue.add(2);
        queue.add(4);
        System.out.println(queue.size);
        System.out.println(queue.max());
        System.out.println(queue.maxAndRemove());
        System.out.println(queue.max());
    }
}