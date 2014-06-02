template<class T,class...>class C{C<T*const,T,C>a;C<T,C>b;};C<int>c;


int main(){
return 0;
}
