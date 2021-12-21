import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.collections.HashSet

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val ansSet = HashSet<Int>()

    var (n, m) = br.readLine().split(' ').map { it.toInt() }
    val maskingBit = ((1 shl n.coerceAtMost(30)) - 1)
    val op1 = Pair(n, (1 shl 30) - 1)
    val op2 = Pair(n / 2, run {
        var bit = 0
        repeat(15) { bit = bit or (1 shl (it * 2 + 1)) }
        bit
    })
    val op3 = Pair((n + 1) / 2, op1.second xor op2.second)
    val op4 = Pair((n + 2) / 3, run {
        var bit = 0
        repeat(10) {
            bit = bit or (1 shl (it * 3))
        }
        bit
    })

    val opArr = arrayOf(op1, op2, op3, op4)

    for (i in 0 until (1 shl 4)) {
        var bit = 0
        var time = 0
        for (j in 0 until 4) {
            if (i and (1 shl j) == 0) continue
            time += opArr[j].first
            bit = bit xor opArr[j].second
        }
        bit = bit and maskingBit

        if (time <= m) ansSet.add(bit)
    }

    bw.write("${ansSet.size}\n")
    bw.close()
}

fun bitPrint(bit:Int){
    for(i in 0 until 30){
        if(bit and (1 shl i)!=0) print(1)
        else print(0)
    }
    println(0)
}
/*
1 0 ans : 1
100000 100000  ans: 7
10 0 ans : 1
10 4 ans : 2
10 3 ans : 1
10 5 ans : 4
10 9 ans : 6
4 0 ans : 1
4 1 ans : 1
4 2 ans : 4
4 3 ans : 4
4 4 ans : 7
4 10 ans : 8
4 50 ans : 8
3 10 ans : 8
13 1249 ans : 8
 */