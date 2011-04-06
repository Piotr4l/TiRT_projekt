simple PoissonGenerator
{
    parameters:
    	double lambda = default(5);
    	volatile double delay = default(100); 
    	int duration = default(0);
		int priority = default(0);
		int sessionId = default(0);
		int packetId = default(0);
		int size = default(500);
    gates:
        output out;
}

simple ExponentialGenerator
{
 	parameters:
    	volatile double delay = default(100); 
    	double alfa = default(3);
    	int duration = default(0);
		int priority = default(0);
		int sessionId = default(0);
		int packetId = default(0);
		int size = default(500);
    gates:
        output out;
}

simple OnOffGenerator
{
    parameters:
		volatile double offInterval  = default(4000); 
    	volatile double delay = default(100); 
        volatile int switchingInterval = default(3); 
    	int duration = default(0);
		int priority = default(0);
		int sessionId = default(0);
		int packetId = default(0);
		int size = default(500);
    gates:
        output out;
}

simple MmppGenerator
{
	parameters:
    	volatile double delay = default(100); 
    	int duration = default(0);
		int priority = default(0);
		int sessionId = default(0);
		int packetId = default(0);
		double alfa = default(3);
		double lambda = default(5);
		int markovDelay = default(10);
		
		int size1 = default(500);
		int size2 = default(1000);
		volatile double offInterval = default(4000); 
        volatile int switchingInterval = default(3);
		int lambda1 = default(5);
		int lambda2 = default(15);
		double on1 = default(0.3);
		double on2 = default(0.3);
    gates:
        output out;
}

simple Receiver
{
    gates:
        input in;
}

network Network1
{
    submodules:
        generator: PoissonGenerator;
        receiver:  Receiver;
    connections:
        generator.out --> receiver.in;
}

network Network2
{
    submodules:
        generator: ExponentialGenerator;
        receiver: Receiver;
    connections:
        generator.out --> receiver.in;
}
network Network3
{
    submodules:
        generator: OnOffGenerator;
        receiver: Receiver;
    connections:
        generator.out --> receiver.in;
}
network Network4
{
    submodules:
        generator: MmppGenerator;
        receiver: Receiver;
    connections:
        generator.out --> receiver.in;
}
