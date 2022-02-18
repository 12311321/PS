fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val (R,C,Q) = br.readLine().split(' ').map{it.toInt()}
    val arr=Array(R+1){Array(C+1){0}}
    repeat(R){r->
        arr[r+1]=arrayOf(0).plus(br.readLine().split(' ').map{it.toInt()})
    }

    val calSum={r1:Int, c1:Int, r2:Int, c2:Int -> arr[r2][c2]-arr[r1-1][c2]-arr[r2][c1-1]+arr[r1-1][c1-1]}
    val calNum={r1:Int,c1:Int,r2:Int,c2:Int->(r2-r1+1)*(c2-c1+1)}
    for(r in 1..R) for(c in 1..C) arr[r][c]+=arr[r-1][c]+arr[r][c-1]-arr[r-1][c-1]
    repeat(Q){
        br.readLine().split(' ').map{it.toInt()}.run{
            bw.write("${calSum(get(0),get(1),get(2),get(3))/calNum(get(0),get(1),get(2),get(3))}\n")
        }
    }
    bw.close()
}