fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val timeArr = Array(br.readLine().toInt()) {
        br.readLine().split(' ').map { it.toInt() }.run { get(0) to get(1) }
    }.apply {
        sortWith { a, b ->
            when {
                a.second > b.second -> 1
                a.second < b.second -> -1
                else -> when {
                    a.first > b.first -> 1
                    a.first < b.first -> -1
                    else -> 0
                }
            }
        }
    }

    var ans = 0
    var lastTime = 0
    for (time in timeArr) {
        if (time.first >= lastTime) {
            ans++
            lastTime = time.second
        }
    }
    bw.write("$ans\n")
    bw.close()
}