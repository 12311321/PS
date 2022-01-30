fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val N = br.readLine().toInt()
    val arr = Array(N) { br.readLine().split(' ').run { get(0).toLong() to get(1).toLong() } }
    var ans = 0L
    val abs= { a:Long -> if(a>0) a else -a}
    for (idx in 1..N - 2) {
        val a = arr[0]
        val b = arr[idx]
        val c = arr[idx + 1]
        ans += a.first * b.second + b.first * c.second + c.first * a.second - a.second * b.first - b.second * c.first - c.second * a.first
    }
    println(String.format("%.1f", abs(ans).toDouble() / 2))
}