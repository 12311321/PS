fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val (N,K) = br.readLine().split(' ').map{it.toInt()}
    val arr=br.readLine().split(' ').map{it.toInt()}
    var s=0
    var n=0
    val dp =Array(N){0L}
    for(e in 0 until N){
        if(e>0) dp[e]=dp[e-1]
        n+=arr[e]
        if(n>=K) dp[e] = dp[e].coerceAtLeast(n.toLong()-K + (if(s==0) 0 else dp[s-1]))
        while(n>=K) n-=arr[s++]
    }

    println(dp.maxOf{it})
}