function dfs(str,index,level,res){
    // console.log(res)
    if(level == 5 || index ==str.length-1){
        if(level == 5 && index ==str.length-1){
            console.log(res.join('.'))
        }
        return ;
    }
    

    for(var i = 1;i < 4;i++){
        var x = str.substr(index+1,i);

        if(parseInt(x)<256 && (x=='0' || !x.startsWith('0'))){
            res.push(x);
            dfs(str,index+i,level+1,res);
            res.pop();
        }
    }
}

dfs("19216801",-1,1,[])
console.log("123".length)