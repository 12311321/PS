fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val (N,M) = br.readLine().split(' ').map{it.toInt()}
    val T = Array(N){br.readLine().toLong()}
    var s=1L
    var e=T.minOf{it}*M
    var ans = e
    while(s<=e){
        val m = (s+e)/2
        if(T.sumOf{m/it}>=M){
            ans=m
            e=m-1
        }else s=m+1
    }
    println(ans)
}