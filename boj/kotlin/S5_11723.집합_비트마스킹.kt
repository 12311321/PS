fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    var bit = 0
    repeat(br.readLine().toInt()) {
        br.readLine().split(' ').run {
            when (get(0)[1]) {
                'd' -> bit = bit or (1 shl get(1).toInt())
                'e' -> bit = bit and ((1 shl get(1).toInt()).inv())
                'h' -> bw.write((if (bit and (1 shl get(1).toInt()) == 0) "0" else "1") + "\n")
                'o' -> bit = bit xor (1 shl get(1).toInt())
                'l' -> bit = (1 shl 21) - 1
                'm' -> bit = 0
            }
        }
    }
    bw.close()
}

fun printBin(bit: Int) {
    for (i in 20 downTo 1) {
        print(if (bit and (1 shl i) == 0) "0" else "1")
    }
    println()
}