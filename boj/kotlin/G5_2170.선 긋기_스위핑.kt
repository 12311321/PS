fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    var ans=0
    var maxPos=Int.MIN_VALUE
    MutableList(br.readLine().toInt()) {
        br.readLine().split(' ').map { it.toInt() }.run { get(0) to get(1) }
    }.apply { sortBy { it.first } }.forEach{
        if(maxPos<it.first) ans+=it.second-it.first
        else if(maxPos<it.second) ans+=it.second-maxPos
        maxPos=maxPos.coerceAtLeast(it.second)
    }
    println(ans)
}