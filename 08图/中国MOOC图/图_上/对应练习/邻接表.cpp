typedef struct GNode * PtrToGNode;
struct GNode{
	int Nv;  //������
	int Ne;  //����
	AdjList G;  //�ڽӱ�

};
typedef PtrToGNode LGraph;  //���ڽӱ�洢��ͼ����


typedef struct Vnode{           //�ڽӱ����͵Ľṹ��
	PtrToAdjVNode FirstEdge;
	
	//DateType Data[MaxVertexNum];  //�涥�������

}AdjList[MaxVertexNum]; //AdjList�ڽӱ�����


typedef struct AdjVNode * PtrToAdjVNode;   //���ṹ��
struct AdjVNode{
	Vertex AdjV;   //�ڽӵ���±�
	WeightType Weight; //��Ȩ��
	PtrToAdjVNode Next;
};

/*
	��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ,ÿ������Ū���״���ʲô����ͻ������ˡ�
*/

typedef int Vertex;
LGraph CreateCraph(int VertexNum){
	Vertex V,W;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	//ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv  - 1)
	for(V=0;V<Graph->Nv;V++){
		Graph->G[V].FirstEdge = NULL;
	}

	return Graph;
}

/*
	�� LGraph�в����
*/
void InsertEdge(LGraph Graph,Edge E){
	PtrToAdjVNode NewNode;

	//�����<V1,V2>
	//ΪV2�����µ��ڽӵ�
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;

	//��V2����V1�ı�ͷ
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;


	//��
}
