simple MmppGenerator
{
	parameters:
		@display("i=block/source");
    	volatile double delay = default(100); 
    	int duration = default(0);
		int priority = default(0);
		int sessionId = default(0);
		int packetId = default(0);
		double alfa = default(3);
		double lambda = default(5);
		int markovDelay = default(10);
		int minPrio = default(0);
		int maxPrio = default(10);
		int size1 = default(500);
		int size2 = default(1000);
		volatile double offInterval = default(4000); 
        volatile int switchingInterval = default(3);
		int lambda1 = default(5);
		int lambda2 = default(15);
		double on1 = default(0.3);
		double on2 = default(0.3);
		
		int genType = default(2);
		
		int minSize = default(10);
		int maxSize = default(20);
    gates:
        output out;
}