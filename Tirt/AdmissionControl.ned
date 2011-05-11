
simple AdmissionControl
{
	parameters:
		@display("i=block/filter");
		int minPrority = default(3);
		int type = default(2);
	gates: 
		input in1;
		input in2;
		input in3;
		input in4;
		output out1;
		output out2;
}
