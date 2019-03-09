//Define the elements in the node
struct node{
};

node seg[4*lim];

node zero;

//Creates the default value of the nodes
inline node base(int a){
   node resp;
   return resp;
}

//Applies the propriety of the join function
inline node join(node a, node b){
   node resp;
   return resp;
}

//Builds the segtree
//Run code as s.build(1, 0, n-1)
void build(int idT, int inicio, int fim){
   if(inicio==fim){
      seg[idT]=base(ele[inicio]);
   }else{
      int m=(inicio+fim)/2;
      build(idT+idT, inicio, m);
      build(idT+idT+1, m+1, fim);
      seg[idT]=join(seg[idT+idT], seg[idT+idT+1]);
   }
}

//Aswer the query. Define the neutral element for this operation and store it on 'zero'
no query(int a, int b, int idT, int inicio, int fim){
   if(fim<a||b<inicio||inicio>fim){
      return zero;
   }
   if(a<=inicio && fim<=b){
      return seg[idT];
   }
   int m=(inicio+fim)/2;
   return join(query(a,b,idT+idT, inicio, m), query(a,b,idT+idT+1, m+1, fim));
}

//Update the value of the nodes
//Run as: s.update(idElement, newElement, 1, 0, n-1)
void update(int a, int novo, int idT, int inicio, int fim){
   if(fim<a|| inicio>a){
      return;
   }
   if(inicio==fim){
      seg[idT]= base(novo);
      return;
   }
   int meio=(inicio+fim)/2;
   update(a,novo, idT+idT, inicio, meio);
   update(a, novo, idT+idT+1, meio+1, fim);
   seg[idT]=join(seg[idT+idT], seg[idT+idT+1]);
}
