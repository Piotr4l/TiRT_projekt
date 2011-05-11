
network Network
{
    parameters:
        @display("bgb=812,587");
        exponentialGen.genType = default(1);
  		mmppGen.genType = default(2);
  		onOffGen.genType = default(3);
  		poissonGen.genType = default(4);

    submodules:
        poissonGen: PoissonGenerator {
            @display("p=123,101");
        }
        mmppGen: MmppGenerator {
            @display("p=216,553");
        }
        exponentialGen: ExponentialGenerator {
            @display("p=73,254");
        }
        onOffGen: OnOffGenerator {
            @display("p=266,62");
        }
        admissionControl: AdmissionControl {
            @display("p=216,319");
        }
        trafficShaper: TrafficShaper {
            @display("p=370,280");
        }
        scheduler: Scheduler {
            @display("p=583,319");
        }
        admissionRejected: Receiver {
            @display("p=84,450");
        }
        shaperRejected: Receiver {
            @display("p=370,140");
        }
        destination1: Receiver {
            @display("p=583,62");
        }
        destination2: Receiver {
            @display("p=709,206");
        }
        destination3: Receiver {
            @display("p=709,450");
        }
        destination4: Receiver {

            @display("p=583,553");
        }
    connections:
        poissonGen.out --> admissionControl.in1;
        mmppGen.out --> admissionControl.in2;
        exponentialGen.out --> admissionControl.in3;
        onOffGen.out --> admissionControl.in4;
        admissionControl.out1 --> trafficShaper.in;
        admissionControl.out2 --> admissionRejected.in;
        trafficShaper.out1 --> scheduler.in;
        trafficShaper.out2 --> shaperRejected.in;
        scheduler.out0 --> destination1.in;
        scheduler.out1 --> destination2.in;
        scheduler.out2 --> destination3.in;
        scheduler.out3 --> destination4.in;
}
