class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node) {
        if(node == 0) return 0;
        map<UndirectedGraphNode*, UndirectedGraphNode*> map_node;
	    deque<UndirectedGraphNode*> deq;
    	deq.push_back(node);
    	while(!deq.empty())
    	{
    		UndirectedGraphNode *p = deq.front();
    		deq.pop_front();
    		UndirectedGraphNode *pnew = new UndirectedGraphNode(p->label);
    		map_node[p] = pnew;
    		for(size_t i = 0; i < p->neighbors.size(); ++i)
    		{
    			if(!map_node.count(p->neighbors[i]))
    			{
    				deq.push_back(p->neighbors[i]);
    			}
    		}
    	}
    	for(map<UndirectedGraphNode*, UndirectedGraphNode*>::const_iterator iter = map_node.begin(); iter != map_node.end(); ++iter)
    	{
    	    UndirectedGraphNode* pold = iter->first;
    	    UndirectedGraphNode* pnew = iter->second;
    	    for(size_t i = 0; i < pold->neighbors.size(); ++i)
    	    {
    	        pnew->neighbors.push_back(map_node[pold->neighbors[i]]);
    	    }
    	}
    	return map_node[node];
    }
};
