fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    fun getGCD(a: Long, b: Long): Long {
        var na = a
        var nb = b
        while (na % nb != 0L) {
            val r = na % nb
            na = nb
            nb = r
        }
        return nb
    }

    val mod = 1000000000L
    val N = br.readLine().toInt()
    val arr1 = br.readLine().split(' ').map { it.toLong() }.toTypedArray()
    val M = br.readLine().toInt()
    val arr2 = br.readLine().split(' ').map { it.toLong() }.toTypedArray()

    var ans = 1L
    var flag = false
    repeat(N) { i ->
        repeat(M) { j ->
            val gcd = getGCD(arr1[i], arr2[j])
            ans *= gcd
            flag = flag or (ans>= mod)
            arr1[i] /= gcd
            arr2[j] /= gcd
            ans %= mod

        }
    }
    bw.write(if(flag) (ans+mod).toString().substring(1) else ans.toString())
    bw.close()

}