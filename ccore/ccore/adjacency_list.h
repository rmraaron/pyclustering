#ifndef _ADJACENCY_LIST_H_
#define _ADJACENCY_LIST_H_

#include "adjacency.h"

#include <unordered_set>


/***********************************************************************************************
*
* @brief   Implementation of adjacency matrix where each node stores its neighbors in unordered
*          set.
*
* @details Unordered ensures maximum performance in case of getting elements by index because only 
*          indexes are used as keys that ensures uniform distribution. It takes less memory
*          than classical matrix representation. And it is faster in case of getting neighbors than
*          bit matrix and classical matrix representation.
*
* @see     adjacency_bit_matrix
* @see     adjacency_matrix
*
***********************************************************************************************/
class adjacency_list : public adjacency_collection {
private:
    typedef std::vector<std::unordered_set<size_t>>     adjacency_list_container;


protected:
    adjacency_list_container     m_adjacency;


public:
    /***********************************************************************************************
    *
    * @brief   Default destructor without arguments is forbiden.
    *
    ***********************************************************************************************/
    adjacency_list(void) = delete;

    /***********************************************************************************************
    *
    * @brief   Default copy constructor.
    *
    * @param[in]  another_matrix: adjacency matrix that should be copied.
    *
    ***********************************************************************************************/
    adjacency_list(const adjacency_list & another_matrix);

    /***********************************************************************************************
    *
    * @brief   Default move constructor.
    *
    * @param[in]  another_matrix: adjacency matrix that should be moved.
    *
    ***********************************************************************************************/
    adjacency_list(adjacency_list && another_matrix);

    /***********************************************************************************************
    *
    * @brief   Adjacency list matrix constructor.
    *
    * @param[in]  node_amount: number of nodes whose connections are described in matrix.
    *
    ***********************************************************************************************/
    adjacency_list(const size_t node_amount);

    /***********************************************************************************************
    *
    * @brief   Default destructor.
    *
    ***********************************************************************************************/
    virtual ~adjacency_list(void);

private:
    static const size_t DEFAULT_EXISTANCE_CONNECTION_VALUE;
    static const size_t DEFAULT_NON_EXISTANCE_CONNECTION_VALUE;

public:
    /***********************************************************************************************
    *
    * @brief   Establishes one-way connection from the first node to the second in adjacency collection.
    *
    * @details Complexity equals to complexity of insertion of std::unrodered_set.
    *
    * @param[in]  node_index1: index of node in the collection that should be connected with another.
    * @param[in]  node_index2: index of another node in the collection that should be connected with
    *                          the node defined by the first argument 'node_index1'.
    *
    ***********************************************************************************************/
    virtual void set_connection(const size_t node_index1, const size_t node_index2);

    /***********************************************************************************************
    *
    * @brief   Removes one-way connection from the first node to the second in adjacency collection.
    *
    * @details Complexity equals to complexity of erasing of std::unrodered_set.
    *
    * @param[in]  node_index1: index of node in the collection that should be disconnected from another.
    * @param[in]  node_index2: index of another node in the collection that should be diconnected from
    *              the node defined by the first argument 'node_index1'.
    *
    ***********************************************************************************************/
    virtual void erase_connection(const size_t node_index1, const size_t node_index2);

    /***********************************************************************************************
    *
    * @brief   Checks existance of connection between specified nodes.
    *
    * @details Complexity equal to searching of std::unrodered_set.
    *
    * @param[in]  node_index1: index of node in the collection.
    * @param[in]  node_index2: index of another node in the collection.
    *
    * @return  'true' - connection between the nodes exists, 'false' - connection does not exist.
    *
    ***********************************************************************************************/
    virtual bool has_connection(const size_t node_index1, const size_t node_index2) const;

    /***********************************************************************************************
    *
    * @brief   Returns vector of indexes of neighbors of specified node in line with adjacency collection.
    *
    * @details Complexity equals to complexity of copying from unordered_set to vector.
    *
    * @param[in]  node_index: index of node in the collection whose neighbors are required.
    * @param[out] node_neighbors: vector of indexes of neighbors of specified node.
    *
    ***********************************************************************************************/
    virtual void get_neighbors(const size_t node_index, std::vector<size_t> & node_neighbors) const;
};

#endif