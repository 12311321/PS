import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val getLength =
        { c: Char -> if (c == '0') 0 else if (c.isLowerCase()) c.code - 'a'.code + 1 else c.code - 'A'.code + 27 }
    val N = br.readLine().toInt()
    val par = Array(N){it}
    val d = Array(N){0}

    fun find(a:Int):Int{
        if(par[a]!=a) par[a]=find(par[a])
        return par[a]
    }

    fun union(a:Int, b:Int):Boolean{
        val pa=find(a)
        val pb=find(b)
        if(pa==pb) return false
        if(d[pa]==d[pb]){
            d[pa]++
            par[pb]=pa
        }else if(d[pa]>d[pb]) par[pb]=pa
        else par[pa]=pb
        return true
    }

    var sum=0
    var cnt=0
    ArrayList<Triple<Int,Int,Int>>().apply{
        repeat(N){s->
            br.readLine().forEachIndexed{e,c->
                val l = getLength(c)
                if(l==0) return@forEachIndexed
                sum+=l
                add(Triple(s,e,l))
            }}
        sortBy{it.third}
    }.forEach{
        if(union(it.first,it.second)){
            sum-=it.third
            cnt++
        }
    }

    if(cnt!=N-1) println("-1") else println(sum)
}