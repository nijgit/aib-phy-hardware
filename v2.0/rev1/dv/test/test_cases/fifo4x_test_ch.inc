    parameter WR_CYCLE   = 2000;
    parameter RD_CYCLE   = 2000;


    always #(WR_CYCLE/2)   wr_clk   = ~wr_clk;

    always #(RD_CYCLE/2)   rd_clk   = ~rd_clk;


  initial begin
    begin
      status = "Reset DUT";
      $display("\n////////////////////////////////////////////////////////////////////////////");
      $display("%0t: Get into Main initial", $time);
      $display("////////////////////////////////////////////////////////////////////////////\n");
      reset_duts ();
      $display("\n////////////////////////////////////////////////////////////////////////////");
      $display("%0t: Finish reset_duts", $time);
      $display("////////////////////////////////////////////////////////////////////////////\n");
      $display("\n////////////////////////////////////////////////////////////////////////////");
      $display("\n////////////////////////////////////////////////////////////////////////////");
      $display("\n//                                                                       ///");
      $display("%0t: set to 4xfifo mode for ms -> sl and sl -> ms", $time);
      $display("\n//                                                                       ///");
      $display("%0t: No dbi enabled", $time);
      $display("////////////////////////////////////////////////////////////////////////////\n");
      avmm_if_m1.cfg_write(17'h208, 4'hf, 32'h0600_0000);
      avmm_if_s1.cfg_write(17'h208, 4'hf, 32'h0600_0000);

      avmm_if_m1.cfg_write(17'h210, 4'hf, 32'h0000_0025);
      avmm_if_s1.cfg_write(17'h210, 4'hf, 32'h0000_0025);

      avmm_if_m1.cfg_write(17'h218, 4'hf, 32'h60c4_0000);
      avmm_if_s1.cfg_write(17'h218, 4'hf, 32'h60c4_0000);

      avmm_if_m1.cfg_write(17'h21c, 4'hf, 32'h0000_0000);
      avmm_if_s1.cfg_write(17'h21c, 4'hf, 32'h0000_0000);

      avmm_if_m1.cfg_write(17'h31c, 4'hf, 32'h0000_0000);
      avmm_if_s1.cfg_write(17'h31c, 4'hf, 32'h0000_0000);

      avmm_if_m1.cfg_write(17'h320, 4'hf, 32'h0000_0000);
      avmm_if_s1.cfg_write(17'h320, 4'hf, 32'h0000_0000);

      avmm_if_m1.cfg_write(17'h324, 4'hf, 32'h0000_0000);
      avmm_if_s1.cfg_write(17'h324, 4'hf, 32'h0000_0000);

      avmm_if_m1.cfg_write(17'h328, 4'hf, 32'h0000_0000);
      avmm_if_s1.cfg_write(17'h328, 4'hf, 32'h0000_0000);

      ms1_tx_fifo_mode = 2'b10;
      sl1_tx_fifo_mode = 2'b10;
      ms1_rx_fifo_mode = 2'b10;
      sl1_rx_fifo_mode = 2'b10;

      run_for_n_pkts_ms1 = 40;
      run_for_n_pkts_sl1 = 40;
      ms1_tx_markbit   = 5'b00100;
      sl1_tx_markbit   = 5'b00100;

      $display("\n////////////////////////////////////////////////////////////////////////////");
      $display("%0t: Performing duts_wakeup", $time);
      $display("////////////////////////////////////////////////////////////////////////////\n");

      duts_wakeup ();
      status = "Waiting for link up";

      $display("\n////////////////////////////////////////////////////////////////////////////");
      $display("%0t: Waiting for link up", $time);
      $display("////////////////////////////////////////////////////////////////////////////\n");

      link_up ();
      status = "Starting data transmission";

      $display("\n////////////////////////////////////////////////////////////////////////////");
      $display("%0t: Starting data transmission", $time);
      $display("////////////////////////////////////////////////////////////////////////////\n");

      fork
         ms1_data_xmit_fifo ();
         ms1_data_rcv_fifo ();
         sl1_data_xmit_fifo ();
         sl1_data_rcv_fifo ();
      join

      status = "Finishing data transmission";
      Finish ();
    end
  end

