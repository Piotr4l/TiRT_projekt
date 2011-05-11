

packet Package {
    int destination;
    int source;
    int sessionId;
    int packetId;
    int priority;
    int size;
    bool isAccepted;
    bool payload[];
}
