int formNumber(int group_no,int aux, int op){
    int val=0;
    int a[32]={0};
    int i=0;
    int len;
    if(op==2){
        len=2*group_no;
        
        a[0]=a[len-1]=1;
        while(aux){
            a[group_no+i]=a[group_no-i-1]=aux&1;
            aux=aux>>1;
            i++;
        }
        
    }
    else if(op==0){
        
        len=2*group_no+1;
        a[0]=a[len-1]=1;
        a[group_no]=0;
        while(aux){
            a[group_no+i+1]=a[group_no-i-1]=aux&1;
            aux=aux>>1;
            i++;
        }
        
        
    }else{
           len=2*group_no+1;
        a[0]=a[len-1]=1;
        a[group_no]=1;
        while(aux){
            a[group_no+i+1]=a[group_no-i-1]=aux&1;
            aux=aux>>1;
            i++;
        }
        
    }
    
    for(i=0;i<len;i++){
        val=val+(1<<i)*a[i];
        }
    
    return val;
    
}





int Solution::solve(int A) {
    if(A==1){
        return 1;
    }
    int group_no=0;
    int count=1;
    int group_offset=0;
    int count_upto=0;
    int op,aux;
    while(count<A){
        
        group_no++;
        count_upto=count;
        count+=(3*1<<(group_no-1));
        
    }
    group_offset=A-count_upto-1;
    
    if(group_offset+1<=1<<(group_no-1)){
        op=2;
        aux=group_offset;
    }
    else{
        if(((group_offset+1)-(1<<(group_no-1)))%2){
            op=0;
        }else{
            op=1;
        }
        
        aux=((group_offset)-(1<<(group_no-1)))/2;
    }
    
    return formNumber(group_no,aux,op);
}
