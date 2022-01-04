fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class BitData(val bit: Int = 0, val num: Int = 0)

    val (N, M, K) = br.readLine().split(' ').map { it.toInt() }
    val arr = Array(N) { br.readLine().split(' ').map { it.toInt() }.toTypedArray() }
    val dp = Array(2) { Array(1 shl M) { Array(K + 1) { Int.MIN_VALUE } } }
    val validBit = ArrayList<BitData>()
    val isAdj = Array(1 shl M) { Array(1 shl M) { false } }
    for (i in 0 until (1 shl M)) {
        var temp = i
        var num = 0
        while (true) {
            if (temp % 4 == 3) break
            num += temp % 2
            temp /= 2
            if (temp == 0) {
                validBit.add(BitData(i, num))
                break
            }
        }
    }

    for (s in 0..validBit.lastIndex) for (e in s + 1..validBit.lastIndex) {
        var ts = validBit[s].bit
        var te = validBit[e].bit
        while (true) {
            if (ts == 0 || te == 0) {
                isAdj[validBit[s].bit][validBit[e].bit] = true
                isAdj[validBit[e].bit][validBit[s].bit] = true
                break
            }
            if (((ts % 2) * (te % 2)) == 1) break
            ts /= 2
            te /= 2

        }
    }

    isAdj[0][0] = true
    val getColBitNum = { bit: Int, r: Int ->
        var sum = 0
        var col = 0
        var nBit = bit
        while (nBit != 0) {
            sum += nBit % 2 * arr[r][col]
            col++
            nBit /= 2
        }
        sum
    }
    dp[1][0][0] = 0

    for (r in 0 until N) {
        val now = r % 2
        val pre = 1 - now
        for (s in validBit) for (e in validBit) {
            if (!isAdj[s.bit][e.bit]) continue
            for (n in 0..K) {
                if (n + e.num > K) break
                if (dp[pre][s.bit][n] == Int.MIN_VALUE) continue
                dp[now][e.bit][n + e.num] =
                    dp[now][e.bit][n + e.num].coerceAtLeast(dp[pre][s.bit][n] + getColBitNum(e.bit, r))
            }
        }
    }

    bw.write(dp[(N - 1) % 2].maxOf { it[K] }.toString())
    bw.close()
}