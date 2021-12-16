import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val seq = Array(101) { 0L }.also { seq ->
        repeat(101) { idx ->
            seq[idx] = (if (idx <= 4) (idx + 2L) / 3 else seq[idx - 5] + seq[idx - 1])
        }
    }
    repeat(br.readLine().toInt()) {
        bw.write(seq[br.readLine().toInt()].toString() + "\n")
    }
    bw.flush()
}