import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

/*
    CountingSort
 */
fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val countingSort=Array(201){ArrayList<String>()}
    repeat(br.readLine().toInt()){
        br.readLine().split(' ').run{
            countingSort[get(0).toInt()].add(get(1))
        }
    }
    for(age in 1..200){
        for(name in countingSort[age]){
            bw.write("$age $name\n")
        }
    }
    bw.flush()
}

/*
    MergeSort
 */
//fun main() {
//    val br = BufferedReader(InputStreamReader(System.`in`))
//    val bw = BufferedWriter(OutputStreamWriter(System.out))
//
//    val arr = Array(br.readLine().toInt()) { br.readLine().split(' ').run { Pair(get(0).toInt(), get(1)) } }
//
//    fun mergeSort(s: Int, e: Int, arr: Array<Pair<Int, String>>): ArrayList<Pair<Int, String>> {
//        if (s == e) return arrayListOf(arr[s])
//        val m = (s + e) / 2
//        val list1 = mergeSort(s, m, arr)
//        val list2 = mergeSort(m + 1, e, arr)
//
//        var idx1 = 0
//        var idx2 = 0
//        val ret = ArrayList<Pair<Int, String>>()
//        while (true) {
//            if (idx1 == list1.size) {
//                while (idx2 < list2.size) {
//                    ret.add(list2[idx2++])
//                }
//                break
//            } else if (idx2 == list2.size) {
//                while (idx1 < list1.size) {
//                    ret.add(list1[idx1++])
//                }
//                break
//            } else {
//                if (list1[idx1].first <= list2[idx2].first) {
//                    ret.add(list1[idx1])
//                    idx1++
//                } else {
//                    ret.add(list2[idx2])
//                    idx2++
//                }
//            }
//        }
//        return ret
//    }
//
//    fun mergeSort(arr: Array<Pair<Int, String>>): ArrayList<Pair<Int, String>> = mergeSort(0, arr.lastIndex, arr)
//
//    mergeSort(arr).forEach {
//        bw.write("${it.first} ${it.second}\n")
//    }
//    bw.flush()
//}



