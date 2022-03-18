fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val N=br.readLine().toInt()
    val arr=Array(N){idx->br.readLine().toInt() to idx}.apply{sortWith{a,b->when{
        a.first>b.first->1
        a.first<b.first->-1
        else->a.second-b.second
    }}}
    var ans=0
    for(i in arr.indices){
        ans = ans.coerceAtLeast(arr[i].second-i)
    }
    println(ans+1)
}