#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    // ### Rule of 3 / rule of 5: ###

    /*
    1, copy constructor
    2, copy assignment
    3, destructor
    #####################
    1, copy constructor
    2, copy assignment
    3, move constructor
    4, move assignment
    5, destructor
    */


    //// STUDENT CODE
    ////
    //#### added ####//
    // copy constructor
    ChatBot(const ChatBot &chatBot);
    // copy assignment
    ChatBot &operator=(const ChatBot &chatBot);
    // move constructor
    /*
    knowledge key points:
    1, pvalue(rvalue) & lvalue
        lvalue has an address that can be accessed.
        pvalue is temporary expression, used for initialise and compute.
        example: int i=42;  lvalue = pvalue, lvalue as named container as rvalues.

    2, rvalue reference with && to store and reference rvalue since c++ 11
        int i = 1;
        int j = 2;
        int k = i + j;
        int &&l = i + j;
        &&l is more efficient than k
    */
    ChatBot(ChatBot &&chatBot);
    // move assignment
    ChatBot &operator=(ChatBot &&chatBot);
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
