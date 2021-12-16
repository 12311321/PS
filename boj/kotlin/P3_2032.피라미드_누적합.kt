import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n: Int
    val m: Int
    val a: Int
    val b: Int
    val c: Int
    val d: Int
    br.readLine().split(' ').map { it.toInt() }.run {
        m = get(0); n = get(1); a = get(2); b = get(3); c = get(4); d = get(5)
    }

    //m,a,c : 가로 n,b,d : 세로
    val array = Array(n) { br.readLine().split(' ').map { it.toInt() }.toTypedArray() }
    val subTotal = { sr: Int, sc: Int, er: Int, ec: Int ->
        var ret = array[er][ec]
        if (sr > 0) ret -= array[sr - 1][ec]
        if (sc > 0) ret -= array[er][sc - 1]
        if (sr > 0 && sc > 0) ret += array[sr - 1][sc - 1]
        ret
    }

    for (r in 0 until n) for (c in 0 until m) {
        if (r > 0) array[r][c] += array[r - 1][c]
        if (c > 0) array[r][c] += array[r][c - 1]
        if (r > 0 && c > 0) array[r][c] -= array[r - 1][c - 1]
    }

    data class Data(val r: Int, val c: Int, val data:Int)

    val minArr=Array(n){Array(m){Data(-1,-1,Int.MAX_VALUE)} }
    val subTotalArr =
        Array(n - d + 1) { row -> Array(m - c + 1) { col -> subTotal(row, col, row + d - 1, col + c - 1) } }
    val pq = PriorityQueue { a: Data, b: Data ->
        when {
            a.data > b.data -> 1
            a.data < b.data -> -1
            else -> 0
        }
    }

    /*
        좌표범위 c+1 ~ c+a-2
       가로 들어가는 개수 a-c-1개
     */
    for(row in 0 until n-d+1){
        pq.clear()
        repeat(a-c-2){col->
            pq.add(Data(row,col,subTotalArr[row][col]))
        }
        for(col in 0 until m-a+3){
            pq.add(Data(row,col+a-c-2,subTotalArr[row][col+a-c-2]))
            while(pq.peek().c<col) pq.poll()
            minArr[row][col]=pq.peek()
        }
    }
//    println("압축")
//    for(row in 0 until n-d+1){
//        for(col in 0 until m-c+1){
//            print("${subTotalArr[row][col]} ")
//        }
//        println()
//    }
//
//    println("가로압축")
//    for(row in 0..n-b+1){
//        for(col in 0 until m-a+3){
//           // print("${minArr[row][col]} ")
//            print("${minArr[row][col].data} ")
//        }
//        println()
//    }

    for(col in 0 until m-a+3){
        pq.clear()
        repeat(b-d-2) { row ->
            pq.add(minArr[row][col])
        }
        for(row in 0 until n-b+3){
            pq.add(minArr[row+b-d-2][col])
            while(pq.peek().r<row) pq.poll()
            minArr[row][col]=pq.peek()
        }
    }
//    println("세로압축")
//        for(row in 0 until n-b+3){
//        for(col in 0 until m-a+3){
//            //print("${minArr[row][col]} ")
//            print("${minArr[row][col].data} ")
//        }
//        println()
//    }


    var h=0
    var outerPos=Pair(-1,-1)
    var innerPos=Pair(-1,-1)
    for(row in 0..n-b)for(col in 0..m-a){
        val sum=subTotal(row,col,row+b-1,col+a-1)-minArr[row+1][col+1].data
        if(sum>h){
            h=sum
            outerPos=Pair(row,col)
            innerPos=Pair(minArr[row+1][col+1].r,minArr[row+1][col+1].c)
        }
    }
//    println("$h $outerPos, $innerPos\n")
    bw.write("${outerPos.second+1} ${outerPos.first+1}\n${innerPos.second+1} ${innerPos.first+1}\n")
    bw.flush()


}
