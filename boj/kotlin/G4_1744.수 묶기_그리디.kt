fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val arr=Array(br.readLine().toInt()){br.readLine().toInt()}.apply{sort()}
    var ans=0
    var p=0
    while(true){
        if(p>=arr.size || arr[p]>=0) break
        if(p+1<arr.size && (arr[p]+arr[p+1]<arr[p]*arr[p+1])){
            ans+=arr[p]*arr[p+1]
            p+=2
        }else{
            ans+=arr[p]
            p++
        }

    }
    p=arr.lastIndex
    while(true){
        if(p<0 || arr[p]<=0) break
        if(p-1>=0 && (arr[p]+arr[p-1]<arr[p]*arr[p-1])){
            ans+=arr[p]*arr[p-1]
            p-=2
        }else{
            ans+=arr[p]
            p--
        }
    }
    bw.write("$ans\n")
    bw.close()
}