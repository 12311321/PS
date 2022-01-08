fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (D, K) = br.readLine().split(' ').map { it.toInt() }
    val dp = Array(D) { Pair(0, 0) }
    dp[0] = Pair(1, 0)
    dp[1] = Pair(0, 1)
    operator fun Pair<Int, Int>.plus(other: Pair<Int, Int>) = Pair(this.first + other.first, this.second + other.second)

    for (i in 2 until D) {
        dp[i] = dp[i - 1] + dp[i - 2]
    }
    var A=1
    var B=(K-dp[D-1].first)/dp[D-1].second
    while(A<=B){
        val sum=dp[D-1].first*A+dp[D-1].second*B
        if(sum==K) break
        if(sum>K) B--
        else A++
    }
    bw.write("$A\n$B\n")
    bw.close()
}