
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class Query(val idx: Int, val s: Int, val e: Int)
     val (N, C) = br.readLine().split(' ').map { it.toInt() }

//    val N = 300000
//    val C = 10000

    val k = kotlin.math.sqrt(N.toDouble()).toInt()
    val colors = br.readLine().split(' ').map { it.toInt() - 1 }.toTypedArray()

//    val colors = Array(N) { it / 30 }

    val M = br.readLine().toInt()

//    val M = 10000
//    val querys = Array(M) { Query(it, it * 30, if (it % 2 == 0) it * 30 else N - 1) }.apply {
//        sortWith { a, b ->
//            when {
//                a.s / k > b.s / k -> 1
//                a.s / k < b.s / k -> -1
//                else -> when {
//                    a.e > b.e -> 1
//                    a.e < b.e -> -1
//                    else -> 0
//                }
//            }
//        }
//    }

    val querys = Array(M) { idx->br.readLine().split(' ').map { it.toInt() - 1 }.run { Query(idx,get(0),get(1)) }}.apply {
        sortWith { a, b ->
            when {
                a.s / k > b.s / k -> 1
                a.s / k < b.s / k -> -1
                else -> when {
                    a.e > b.e -> 1
                    a.e < b.e -> -1
                    else -> 0
                }
            }
        }
    }

    val num = Array(C) { 0 }
    val ans = Array(M) { "" }
    var ns = 0
    var ne = -1

    fun getAns():String{
        var maxNum=-1
        var maxIdx=0
        for(i in 0 until C){
            if(num[i]>maxNum){
                maxNum=num[i]
                maxIdx=i
            }
        }
        return if((ne-ns+1)/2<maxNum) "yes ${maxIdx+1}" else "no"
    }


    for (query in querys) {
        while (ne != query.e) {
            if (ne < query.e) {
                ne++
                num[colors[ne]]++
            } else {
                num[colors[ne]]--
                ne--
            }
        }
        while (ns != query.s) {
            if (ns < query.s) {
                num[colors[ns]]--
                ns++
            } else {
                ns--
                num[colors[ns]]++
            }
        }
        ans[query.idx] = getAns()
    }
    ans.forEach {
        bw.write("$it\n")
    }
    bw.close()
}