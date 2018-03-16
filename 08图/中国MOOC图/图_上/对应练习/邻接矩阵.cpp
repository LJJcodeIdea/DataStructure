/*
��һ����ά��������ʾ��
����ĺᡢ���±궼�����㡣
���磺
	������ һ�� G[MaxVertexNum] [MaxVertexNum]���ڽӾ���
	G[i][j]  ���� ���� i  �� ����j �ߣ���ô�͸� G[i][j] ��ֵ 1
	         ������û�б���������ô�͸� G[i][j] ��ֵ 0��
*/


/*
1���򵥵��ڽӾ���
*/
#define MaxVertexNum  10  //�趥�������Ϊ 10 ��
typedef int WeightType;   //������Ҫ�ı��ڽӾ�������ͣ��������ַ���

int Nv;  //������
int Ne;  //����
Weightype G[MaxVertexNum][MaxVertexNum];

/*
��1���Ż�
2��ģ�黯��
*/
typedef int Datatype;
typedef struct GNode * PtrToGNode;
struct GNode{
	int Nv;  //������
	int Ne;  //����
	Weightype G[MaxVertexNum][MaxVertexNum];
	//DateType Data[MaxVertexNum];  //�涥�������
};
typedef PtrToGNode MGraph;  //���ڽӾ���洢��ͼ����

/*
	3����ʼ��һ��ͼ����VertexNum�����㣬����û��ͼ
*/
typedef int Vertex;  //�ö����±��ʾ���㣬Ϊ����
MGraph CreateGraph(int VertexNum){
	Vertex V,W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	/* Ĭ�϶����Ŵ�0��ʼ���� (Graph->Nv -1) */
	for(V=0;V<Graph->Nv;V++)
		for(W=0;W<Graph->Nv;W++)
			Graph->G[V][W] = 0;

	return Graph;
}


/*
	4����MGraph�в����
*/

typedef struct ENode * PtrToENode;  
struct  ENode{						//�߽�㣬
	Vertex V1,V2;				//����Ҫ�е� �������㡣
	WeightType Weight;			//Ȩ��
};
typedef PtrToENode Edge;

void InsertEdge(MGraph Graph,Edge E)
{
	//�����<V1,V2>
	Graph->G[E->V1][E->V2]  = E->Weight;

	//��������ͼ����Ҫ�����<V2,V1>
	Graph->G[E->V2][E->V1]  =  E->Weight;
}


/*
  5������һ��������ͼ
*/
MGraph BuildGraph(){
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv,i;

	scanf("%d",&Nv);  //����ͼ���ܶ�����
	Graph = CreateGraph(Nv);  //����ͼ������ͼ���г�ʼ��
	scanf("%d",&(Graph->Ne));  //����ͼ�ı���
	
	//�����
	if(Graph->Ne != 0){
		E = (Edge)malloc(sizeof(struct ENode));
		for(i = 0;i<Graph->Ne;i++){
			scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
			InsertEdge(Graph,E);
		}
	}

	//������������ݵĻ�����������
/*	for(V=0;V<Graph->Nv;V++){
		scanf(" %d",&(Graph->Data[V]));
	
	return Graph;
	}
*/
}


//������Ӧ����С����Ŀ��д����Ĵ���͹���
int G[MAXN][MAXN],Nv,Ne;  //ͼֱ�Ӷ���Ϊȫ�ֱ���
void BuildGraph(){
	int i,j,v1,v2,w;

	scanf("%d",&Nv);

	//	��ͼ���г�ʼ��
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


