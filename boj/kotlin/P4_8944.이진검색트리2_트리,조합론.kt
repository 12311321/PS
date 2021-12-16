import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val mod = 9999991L
    val comb=Array(21){Array(21){0L} }
    for(n in 0 until 21){
        comb[n][0]=1L
        comb[n][n]=1L
        for(k in 1 until n){
            comb[n][k]=(comb[n-1][k-1]+comb[n-1][k])%mod
        }
    }

    data class Node(val s: Int, val e: Int, val num: Int, var left: Node? = null, var right: Node? = null)

    fun DFS(node:Node):Long{
        var leftNum=0
        var rightNum=0
        var leftDp=1L
        var rightDp=1L
        if(node.left!=null){
            leftDp=DFS(node.left!!)
            leftNum=node.left!!.run{e-s+1}
        }
        if(node.right!=null){
            rightDp=DFS(node.right!!)
            rightNum=node.right!!.run{e-s+1}
        }
        return (((leftDp*rightDp)%mod)*comb[leftNum+rightNum][leftNum])%mod
    }
    repeat(br.readLine().toInt()) {
        val N = br.readLine().toInt()
        var root: Node? = null
        br.readLine().split(' ').map { it.toInt() }.forEach { data ->
            if (root == null) {
                root = Node(1, N, data)
            }
            else {
                var now = root
                while (true) {
                    val child = if (now!!.num > data) now.left else now.right
                    if (child == null) {
                        if (now.num > data) {
                            now.left = Node(now.s, now.num - 1, data)
                        } else {
                            now.right = Node(now.num + 1, now.e, data)
                        }
                        break
                    }
                    now = child
                }
            }
        }
        bw.write(DFS(root!!).toString()+"\n")

    }
    bw.flush()
}

