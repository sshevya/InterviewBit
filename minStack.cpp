stack<int> st;
stack<int> minst;

MinStack::MinStack() {
    while(!st.empty()){
        st.pop();
    }
    while(!minst.empty()){
    minst.pop();
        
    }
}

void MinStack::push(int x) {

    if(minst.size()==0){
        minst.push(x);
    }else{
        if(x<=minst.top()){
            minst.push(x);
        }else{
            minst.push(minst.top());
        }
    }
    st.push(x);
    
    
    
}

void MinStack::pop() {
    if(!st.empty()){
        st.pop();
        minst.pop();
    }
}

int MinStack::top() {
    if(!st.empty()){
        return st.top();
    }
    return -1;
}

int MinStack::getMin() {
    if(!minst.empty()){
        return minst.top();
        
    }else{
        return -1;
    }
}

