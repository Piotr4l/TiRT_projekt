simple ExponentialGenerator
{
 	parameters:
 		@display("i=block/source");
    	volatile double delay = default(100); 
    	double alfa = default(3);
    	int duration = default(0);
		int priority = default(0);
		int sessionId = default(0);
		int packetId = default(0);
		int minPrio = default(0);
		int maxPrio = default(10);
		
		int genType = default(1);
		
		int minSize = default(10);
		int maxSize = default(20);
    gates:
        output out;
}