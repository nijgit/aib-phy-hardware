// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2019 Intel Corporation. 
// *****************************************************************************
// *****************************************************************************
// Copyright © 2016 Altera Corporation.                                           
// *****************************************************************************
//  Module Name :  c3lib_and2_lcell                                  
//  Date        :  Fri Apr 29 18:00:48 2016                                 
//  Description :  2-input AND gate
// *****************************************************************************

module  c3lib_and2_lcell( 

  // Functional IOs
  input  logic	in0,
  input	 logic	in1,
  output logic	out

); 

c3lib_and2_svt_4x u_c3lib_and2_svt_4x(

  .in0	( in0 ),
  .in1	( in1 ),
  .out	( out )

);

endmodule 

