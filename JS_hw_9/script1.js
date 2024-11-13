"use strict";

//LOADING 1///////////////////////////////////////////////
{
    $("#load_1").click(load1Up());
    
    function load1Up(){
        $("#load_1_1").animate({
            marginTop: "-20px",
            height: "35px"
        }, 250, "swing")
        .animate({
            marginTop: "+=2.5px"
        }, {
            duration: 100,
            complete:
            function(){
                $("#load_1_2").animate({
                    marginTop: "-20px",
                    height: "35px"
                }, 250, "swing")
                .animate({
                    marginTop: "+=2.5px"
                }, {
                    duration: 100,
                    complete:
                    function(){
                        $("#load_1_3").animate({
                            marginTop: "-20px",
                            height: "35px"
                        }, 250, "swing")
                        .animate({
                            marginTop: "+=2.5px"
                        }, {
                            duration: 100,
                            complete: load1Down()
                        });
                    }
                });
            }
        });
    }
    
    function load1Down(){
        $("#load_1_1").animate({
            marginTop: "0px",
            height: "15px"
        }, 250, "swing")
        .animate({
            marginTop: "-=2.5px"
        }, {
            duration: 100,
            complete:
            function(){
                $("#load_1_2").animate({
                    marginTop: "0px",
                    height: "15px"
                }, 250, "swing")
                .animate({
                    marginTop: "-=2.5px"
                }, {
                    duration: 100,
                    complete:
                    function(){
                        $("#load_1_3").animate({
                            marginTop: "0px",
                            height: "15px"
                        }, 250, "swing")
                        .animate({
                            marginTop: "-=2.5px"
                        }, {
                            duration: 100,
                            complete: load1Up()
                        });
                    }
                });
            }
        });
    }
}

//LOADING 2///////////////////////////////////////////////
{
    $("#load_2").click(load2());
            
    function load2(){
        $("#load_2_2").animate({
            width: "15px"
        }, 450, "swing");
        $("#load_2_1").animate({
            width: "30px",
            marginLeft: "-=2.5px"
        }, {
            duration: 450,
            easing: "swing",
            complete: function(){
                $("#load_2_3").animate({
                    width: "15px",
                    marginLeft: "-=2.5px"
                }, 450, "swing");
                $("#load_2_2").animate({
                    width: "30px"
                }, {
                    duration: 450,
                    easing: "swing",
                    complete: function(){
                        $("#load_2_1").animate({
                            width: "15px",
                            marginLeft: "+=2.5px"
                        }, 450, "swing");
                        $("#load_2_3").animate({
                            width: "30px",
                            marginLeft: "+=2.5px"
                        }, {
                            duration: 450,
                            easing: "swing",
                            complete: function(){
                                $("#load_2_2").animate({
                                    width: "15px"
                                }, 450, "swing");
                                load2();
                            }
                        });
                    }
                });
            }
        });
    }
}

//LOADING 3///////////////////////////////////////////////
{
    $("load_3").click(load3Up());
            
    function load3Up(){
        $("#load_3_1").animate({
            marginTop: "-=10px"
        }, {
            duration: 200,
            easing: "swing",
            complete: function(){
                $("#load_3_2").animate({
                    marginTop: "-=10px"
                }, {
                    duration: 200,
                    easing: "swing",
                    complete: function(){
                        $("#load_3_3").animate({
                            marginTop: "-=10px"
                        }, {
                            duration: 200,
                            easing: "swing",
                            complete: load3Down()
                        });
                    }
                });
            }
        });
    }
    
    function load3Down(){
        $("#load_3_1").animate({
            marginTop: "+=10px"
        }, {
            duration: 200,
            easing: "swing",
            complete: function(){
                $("#load_3_2").animate({
                    marginTop: "+=10px"
                }, {
                    duration: 200,
                    easing: "swing",
                    complete: function(){
                        $("#load_3_3").animate({
                            marginTop: "+=10px"
                        }, {
                            duration: 200,
                            easing: "swing",
                            complete: load3Up()
                        });
                    }
                });
            }
        });
    }
}

//LOADING 6///////////////////////////////////////////////
{
    $("#load_6").click(load6(100));
            
    function load6Help(selector){
        $(selector).animate({
                    opacity: "+=0.16"
        }, 100);
    }
    
    function load6(duration){
        $("#load_6_1").animate({
            opacity: "0"
        }, {
            duration: duration,
            complete: function(){
                load6Help("#load_6_1");
                $("#load_6_2").animate({
                    opacity: "0"
                }, {
                    duration: duration,
                    complete: function(){
                        load6Help("#load_6_1");
                        load6Help("#load_6_2");
                        $("#load_6_3").animate({
                            opacity: "0"
                        }, {
                            duration: duration,
                            complete: function(){
                                load6Help("#load_6_1");
                                load6Help("#load_6_2");
                                load6Help("#load_6_3");
                                $("#load_6_4").animate({
                                    opacity: "0"
                                }, {
                                    duration: duration,
                                    complete: function(){
                                        load6Help("#load_6_1");
                                        load6Help("#load_6_2");
                                        load6Help("#load_6_3");
                                        load6Help("#load_6_4");
                                        $("#load_6_5").animate({
                                            opacity: "0"
                                        }, {
                                            duration: duration,
                                            complete: function(){
                                                load6Help("#load_6_1");
                                                load6Help("#load_6_2");
                                                load6Help("#load_6_3");
                                                load6Help("#load_6_4");
                                                load6Help("#load_6_5");
                                                $("#load_6_6").animate({
                                                    opacity: "0"
                                                }, {
                                                    duration: duration,
                                                    complete: function(){
                                                        load6Help("#load_6_1");
                                                        load6Help("#load_6_2");
                                                        load6Help("#load_6_3");
                                                        load6Help("#load_6_4");
                                                        load6Help("#load_6_5");
                                                        load6Help("#load_6_6");
                                                        $("#load_6_7").animate({
                                                            opacity: "0"
                                                        }, {
                                                            duration: duration,
                                                            complete: function(){
                                                                load6Help("#load_6_1");
                                                                load6Help("#load_6_2");
                                                                load6Help("#load_6_3");
                                                                load6Help("#load_6_4");
                                                                load6Help("#load_6_5");
                                                                load6Help("#load_6_6");
                                                                load6Help("#load_6_7");
                                                                $("#load_6_8").animate({
                                                                    opacity: "0"
                                                                }, {
                                                                    duration: duration,
                                                                    complete: function(){
                                                                        load6Help("#load_6_2");
                                                                        load6Help("#load_6_3");
                                                                        load6Help("#load_6_4");
                                                                        load6Help("#load_6_5");
                                                                        load6Help("#load_6_6");
                                                                        load6Help("#load_6_7");
                                                                        load6Help("#load_6_8");
                                                                        $("#load_6_9").animate({
                                                                            opacity: "0"
                                                                        }, {
                                                                            duration: duration,
                                                                            complete: function(){
                                                                                load6Help("#load_6_3");
                                                                                load6Help("#load_6_4");
                                                                                load6Help("#load_6_5");
                                                                                load6Help("#load_6_6");
                                                                                load6Help("#load_6_7");
                                                                                load6Help("#load_6_8");
                                                                                load6Help("#load_6_9");
                                                                                $("#load_6_10").animate({
                                                                                    opacity: "0"
                                                                                }, {
                                                                                    duration: duration,
                                                                                    complete: function(){
                                                                                        load6Help("#load_6_4");
                                                                                        load6Help("#load_6_5");
                                                                                        load6Help("#load_6_6");
                                                                                        load6Help("#load_6_7");
                                                                                        load6Help("#load_6_8");
                                                                                        load6Help("#load_6_9");
                                                                                        $("#load_6_10").animate({
                                                                                            opacity: "+=0.16"
                                                                                        }, {
                                                                                            duration: duration,
                                                                                            complete: function(){
                                                                                                load6Help("#load_6_5");
                                                                                                load6Help("#load_6_6");
                                                                                                load6Help("#load_6_7");
                                                                                                load6Help("#load_6_8");
                                                                                                load6Help("#load_6_9");
                                                                                                $("#load_6_10").animate({
                                                                                                    opacity: "+=0.16"
                                                                                                }, {
                                                                                                    duration: duration,
                                                                                                    complete: function(){
                                                                                                        load6Help("#load_6_6");
                                                                                                        load6Help("#load_6_7");
                                                                                                        load6Help("#load_6_8");
                                                                                                        load6Help("#load_6_9");
                                                                                                        $("#load_6_10").animate({
                                                                                                            opacity: "+=0.16"
                                                                                                        }, {
                                                                                                            duration: duration,
                                                                                                            complete: function(){
                                                                                                                load6Help("#load_6_7");
                                                                                                                load6Help("#load_6_8");
                                                                                                                load6Help("#load_6_9");
                                                                                                                $("#load_6_10").animate({
                                                                                                                    opacity: "+=0.16"
                                                                                                                }, {
                                                                                                                    duration: duration,
                                                                                                                    complete: function(){
                                                                                                                        load6Help("#load_6_8");
                                                                                                                        load6Help("#load_6_9");
                                                                                                                        $("#load_6_10").animate({
                                                                                                                            opacity: "+=0.16"
                                                                                                                        }, {
                                                                                                                            duration: duration,
                                                                                                                            complete: function(){
                                                                                                                                load6Help("#load_6_9");
                                                                                                                                $("#load_6_10").animate({
                                                                                                                                    opacity: "+=0.16"
                                                                                                                                }, {
                                                                                                                                    duration: duration,
                                                                                                                                    complete: function(){
                                                                                                                                        $("#load_6_10").animate({
                                                                                                                                            opacity: "+=0.16"
                                                                                                                                        }, {
                                                                                                                                            duration: duration,
                                                                                                                                            complete: load6(duration)
                                                                                                                                        });
                                                                                                                                    }
                                                                                                                                });
                                                                                                                            }
                                                                                                                        });
                                                                                                                    }
                                                                                                                });
                                                                                                            }
                                                                                                        });
                                                                                                    }
                                                                                                });
                                                                                            }
                                                                                        });
                                                                                    }
                                                                                });
                                                                            }
                                                                        });
                                                                    }
                                                                });
                                                            }
                                                        });
                                                    }
                                                });
                                            }
                                        });
                                    }
                                });
                            }
                        });
                    }
                });
            }
        });
    }
}

//LOADING 8///////////////////////////////////////////////
{
    $("#load_8").click(load8());
    
    function load8(){
        $("#load_8_1").animate({
            width: "+=25px",
            height: "+=7px"
        }, {
            duration: 850,
            easing: "swing"
        });
        $("#load_8_1").animate({
            width: "-=25px",
            height: "-=7px"
        }, {
            duration: 850,
            easing: "swing"
        });
        load8();
    }
}

//LOADING 10//////////////////////////////////////////////
{
    
}