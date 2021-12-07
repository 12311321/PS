import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val alpMap = HashMap<Char, Int>()
    var ans = 0
    repeat(br.readLine().toInt()) {
        alpMap.clear()
        var flag = false
        br.readLine().forEachIndexed { idx, c ->
            if (alpMap[c] != null && alpMap[c] != idx - 1) flag = true
            alpMap[c] = idx
        }
        ans = if (flag) ans else ans + 1
    }
    bw.write(ans.toString() + "\n")
    bw.flush()
}