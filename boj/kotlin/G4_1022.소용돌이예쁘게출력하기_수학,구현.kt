fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val(r1,c1,r2,c2) = br.readLine().split(' ').map{it.toInt()}
    val ans=Array(r2-r1+1){Array(c2-c1+1){""} }

    val getAbs={a:Int->if(a<0)-a else a}
    val getStr={n:String,s:Int->StringBuilder(" ".repeat(s-n.length)).append(n).toString()}
    for(r in r1..r2) for(c in c1..c2){
        val level=getAbs(r).coerceAtLeast(getAbs(c))
        var base=(2*level-1).let{it*it}
        if(level==0)
        else if(r==level) base+=(7*level+c) //아래
        else if(c==-level) base+=(5*level+r)
        else if(r==-level) base+=(3*level-c)
        else base+=(level-r)
        ans[r-r1][c-c1]=base.toString()
    }
    val maxStrLength=ans.maxOf{r->r.maxOf{c->c.length}}
    for(r in r1..r2){
        for(c in c1..c2){
            bw.write("${getStr(ans[r-r1][c-c1],maxStrLength)} ")
        }
        bw.write("\n")
    }
    bw.close()
}