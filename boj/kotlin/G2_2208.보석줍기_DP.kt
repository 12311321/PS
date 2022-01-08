fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (N,M)= br.readLine().split(' ').map{it.toInt()}
    val arr=Array(N){br.readLine().toInt()}
    val preSum=Array(N+1){0}
    for(i in N-1 downTo 0){ preSum[i]=(preSum[i+1]+arr[i]).coerceAtLeast(0) }
    var sum=0

    for(i in 0 until M) sum+=arr[i]
    var ans=(sum+preSum[M]).coerceAtLeast(0)
    for(i in M until N){
        sum+=arr[i]-arr[i-M]
        ans=ans.coerceAtLeast(sum+preSum[i+1])
    }
    bw.write("$ans\n")
    bw.close()
}