fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val getAbs={a:Int->if(a<0) -a else a}
    val (N, L) = br.readLine().split(' ').map { it.toInt() }
    val arr = Array(N) {br.readLine().toInt() to it}.apply { sortBy { getAbs(it.first) } }
    val arr2= arr.sortedBy{if(it.first>0) L-it.first else -it.first }

    var l=0
    var r=N-1
    var idx=0
    while(l<r){
        if(arr2[idx].first>0) r--
        else l++
        idx++
    }

    println("${arr[l].second+1} ${if(arr2.last().first>0) L-arr2.last().first else -arr2.last().first} ")
}