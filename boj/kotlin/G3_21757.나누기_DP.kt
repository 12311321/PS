fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val N = br.readLine().toInt()
    val arr = br.readLine().split(' ').map{it.toLong()}
    val dp = Array(N+1){Array(5){0L} }
    var sum=0L
    if(((arr.sumOf{it})%4)==0L){
        val p = arr.sumOf{it}/4
        for(i in 1..N){
            sum+=arr[i-1]
            dp[i-1][0]=1
            for(j in 1..4){
                dp[i][j]=dp[i-1][j]
                if(p*j==sum) dp[i][j]+=dp[i-1][j-1]
            }
        }
    }
    println(dp[N-1][3])
}