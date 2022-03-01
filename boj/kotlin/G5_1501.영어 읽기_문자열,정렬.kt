fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val strMap = HashMap<String, Long>()
    fun strToCode(str: String): String {
        if (str.length <= 2) return str
        return StringBuilder().append(str[0]).append(str.last())
            .append(str.substring(1, str.lastIndex).toCharArray().apply { sort() }).toString()
    }


    strMap.clear()
    repeat(br.readLine().toInt()) {
        val code = strToCode(br.readLine())
        strMap[code] = strMap.getOrDefault(code, 0L) + 1L
    }

    repeat(br.readLine().toInt()) {
        var ans = 1L
        br.readLine().split(' ').forEach { str ->
            if (str.isEmpty()) return@forEach
            val code = strToCode(str)
            ans *= strMap.getOrDefault(code, 0L)
        }
        bw.write("$ans\n")
    }
    bw.close()
}