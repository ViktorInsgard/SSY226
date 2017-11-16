load_system('closed_loop');
set_param('closed_loop/Manual Switch', 'sw', '1');

warning('off', 'Simulink:Engine:OutputNotConnected');
warning('off', 'Simulink:Engine:InputNotConnected');

InitBreach;
B = BreachSimulinkSystem('closed_loop');

B.PrintSignals();