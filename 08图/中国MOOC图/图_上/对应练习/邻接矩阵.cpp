/*
用一个二维数组来表示。
数组的横、纵下标都代表顶点。
例如：
	建立了 一个 G[MaxVertexNum] [MaxVertexNum]的邻接矩阵。
	G[i][j]  假如 顶点 i  和 顶点j 边，那么就给 G[i][j] 赋值 1
	         若它们没有边相连，那么就给 G[i][j] 赋值 0；
*/


/*
1、简单的邻接矩阵
*/
#define MaxVertexNum  10  //设顶点数最多为 10 个
typedef int WeightType;   //根据需要改变邻接矩阵的类型，现在是字符型

int Nv;  //顶点数
int Ne;  //边数
Weightype G[MaxVertexNum][MaxVertexNum];

/*
对1的优化
2、模块化：
*/
typedef int Datatype;
typedef struct GNode * PtrToGNode;
struct GNode{
	int Nv;  //顶点数
	int Ne;  //边数
	Weightype G[MaxVertexNum][MaxVertexNum];
	//DateType Data[MaxVertexNum];  //存顶点的数据
};
typedef PtrToGNode MGraph;  //以邻接矩阵存储的图类型

/*
	3、初始化一个图。有VertexNum个顶点，但是没有图
*/
typedef int Vertex;  //用顶点下标表示顶点，为整形
MGraph CreateGraph(int VertexNum){
	Vertex V,W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	/* 默认顶点编号从0开始，到 (Graph->Nv -1) */
	for(V=0;V<Graph->Nv;V++)
		for(W=0;W<Graph->Nv;W++)
			Graph->G[V][W] = 0;

	return Graph;
}


/*
	4、向MGraph中插入边
*/

typedef struct ENode * PtrToENode;  
struct  ENode{						//边结点，
	Vertex V1,V2;				//至少要有的 两个顶点。
	WeightType Weight;			//权重
};
typedef PtrToENode Edge;

void InsertEdge(MGraph Graph,Edge E)
{
	//插入边<V1,V2>
	Graph->G[E->V1][E->V2]  = E->Weight;

	//若是无向图，还要插入边<V2,V1>
	Graph->G[E->V2][E->V1]  =  E->Weight;
}


/*
  5、建立一个完整的图
*/
MGraph BuildGraph(){
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv,i;

	scanf("%d",&Nv);  //输入图的总顶点数
	Graph = CreateGraph(Nv);  //创建图，并对图进行初始化
	scanf("%d",&(Graph->Ne));  //输入图的边数
	
	//插入边
	if(Graph->Ne != 0){
		E = (Edge)malloc(sizeof(struct ENode));
		for(i = 0;i<Graph->Ne;i++){
			scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
			InsertEdge(Graph,E);
		}
	}

	//如果顶点有数据的话，读入数据
/*	for(V=0;V<Graph->Nv;V++){
		scanf(" %d",&(Graph->Data[V]));
	
	return Graph;
	}
*/
}


//仅仅是应付，小白题目，写下面的代码就够了
int G[MAXN][MAXN],Nv,Ne;  //图直接定义为全局变量
void BuildGraph(){
	int i,j,v1,v2,w;

	scanf("%d",&Nv);

	//	对图进行初始化
	for(i=0;i<Nv;i++)
		for(j=0;j<Nv;j++)
			G[i][j] = 0;

	scanf("%d",&Ne);

	for(i=0;i<Ne;i++){
		scanf("%d %d %d",&v1,&v2,&w);

		G[v1][v2] = w;
		G[v2][v1] = w;
	}
}


