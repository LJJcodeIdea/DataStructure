typedef struct GNode * PtrToGNode;
struct GNode{
	int Nv;  //顶点数
	int Ne;  //边数
	AdjList G;  //邻接表

};
typedef PtrToGNode LGraph;  //以邻接表存储的图类型


typedef struct Vnode{           //邻接表类型的结构体
	PtrToAdjVNode FirstEdge;
	
	//DateType Data[MaxVertexNum];  //存顶点的数据

}AdjList[MaxVertexNum]; //AdjList邻接表类型


typedef struct AdjVNode * PtrToAdjVNode;   //结点结构体
struct AdjVNode{
	Vertex AdjV;   //邻接点的下标
	WeightType Weight; //边权重
	PtrToAdjVNode Next;
};

/*
	初始化一个有VertexNum个顶点但没有边的图,每个变量弄明白代表什么，你就会明白了。
*/

typedef int Vertex;
LGraph CreateCraph(int VertexNum){
	Vertex V,W;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	//注意：这里默认顶点编号从0开始，到(Graph->Nv  - 1)
	for(V=0;V<Graph->Nv;V++){
		Graph->G[V].FirstEdge = NULL;
	}

	return Graph;
}

/*
	向 LGraph中插入边
*/
void InsertEdge(LGraph Graph,Edge E){
	PtrToAdjVNode NewNode;

	//插入边<V1,V2>
	//为V2建立新的邻接点
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;

	//将V2插入V1的表头
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;


	//将
}
