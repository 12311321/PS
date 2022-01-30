fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val (K,N) = br.readLine().split(' ').map{it.toLong()}
    val arr=Array(K.toInt()){br.readLine().toLong()}
    var s=1L
    var e=Int.MAX_VALUE.toLong()
    var ans=0L
    while(s<=e){
        var num=0L
        val m=(s+e)/2
        arr.forEach{num+=it/m}
        if(num>=N){
            ans=m
            s=m+1
        }else e=m-1
    }
    println(ans)
}