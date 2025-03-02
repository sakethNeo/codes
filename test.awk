BEGIN{
    FS=":"
    ind=0
    lar=0
    smol=0
}
if($7 ~ /India/){
    ind++
    In[ind]=$1 # array indexing starts from 1
} 
n=split($7,country,",")
{
    if($2=="sauropod"){
        t=int($6)
        printf("%d",t)
        list[i]=list[i] " " $1
        for(c in list){
            printf("%-15s: %s",c,list[c])
        }
        # ENVIRON IS A BUILTIN ASSOSIATED ARRAY
        getline n < "-"
        printf("shit") > "avg.txt" # overwrite
        print "" >> "avg.txt" # append
    }
}   
END{
    print "that's all I have bye" $1
}
