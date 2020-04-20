stack<int> st;
stack<int> minst;
/* two approaches:
First:
while pushing element, push directly in original stack but push in minstack if it is smaller than top el, otherwise just push the top element again
And while popping pop from both the stacks dircetly; The minstack stores min element till that number and is of the same size as original

Second:
While pushing, push in minstack only if a smaller element comes and while popping, pop from original stack and pop from minstack only if the popped element is 
smaller than top element of minstack, because min of stack will be changed if min element gets popped out of original stack

*/




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

