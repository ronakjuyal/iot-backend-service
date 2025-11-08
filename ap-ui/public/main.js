const URL_PREFIX =  `http://${window.location.hostname}`; //"http://192.168.1.113" //
var _productInfo = {};

function validateEmail(email) {
  const re = /^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
  return re.test(String(email).toLowerCase());
}

function productCodeToName(code) {
  if(code == "sinric.devices.types.SWITCH") return "Switch";
  else if(code == "sinric.devices.types.DIMMABLE_SWITCH") return "Switch with Dimming";
  else if(code == "sinric.devices.types.LIGHT") return "Smart Light Bulb";
  else if(code == "sinric.devices.types.DOORBELL") return "Doorbell";
  else if(code == "sinric.devices.types.TEMPERATURESENSOR") return "Temperature Sensor";
  else if(code == "sinric.devices.types.AC_UNIT") return "Window AC Unit";
  else if(code == "sinric.devices.types.FAN") return "Fan";
  else if(code == "sinric.devices.types.MOTION_SENSOR") return "Motion Sensor";
  else if(code == "sinric.devices.types.CONTACT_SENSOR") return "Contact Sensor";
  else if(code == "sinric.devices.types.THERMOSTAT") return "Thermostat";
  else if(code == "sinric.devices.types.TV") return "TV";
  else if(code == "sinric.devices.types.SPEAKER") return "Smart Speaker";
  else if(code == "sinric.devices.types.SMARTLOCK") return "Smart Lock";
  else if(code == "sinric.devices.types.BLIND") return "Blinds";
  else if(code == "sinric.devices.types.GARAGE_DOOR") return "Garage Door"; 
  else {
    return "Custom";
  }
}

function enableDisableTab(tab, enable = false) {
  if(enable) {
    $(`#pills-tab a[href="#${tab}"]`).removeClass('disabled');
  } else {
    $(`#pills-tab a[href="#${tab}"]`).addClass('disabled');
  }
}

function navigateToTab(tab) { 
  $(`#pills-tab a[href="#${tab}"]`).tab('show'); // Select tab by name 
}

function createAccount() {
  const fullName =  $("#createAccountModal").find('input[id="inputFullName"]').val().trim();
  const email =  $("#createAccountModal").find('input[id="inputMail"]').val().trim();
  const password =  $("#createAccountModal").find('input[id="inputPassword"]').val().trim();
  const timeZone =  $("#createAccountModal").find('select[id="selectTimezone"]').val().trim();
  const temperatureScale =  $("#createAccountModal").find('select[id="selectTemperatureScale"]').val().trim();
     
  if(fullName == "") {
    return $('#validationErrors').html("Invalid Full name!");
  }
 
  if(email.length < 3 || !validateEmail(email)) {
    return $('#validationErrors').html("Invalid Email!");
  }

  if(password.length < 5) {
    return $('#validationErrors').html("Password must have at least 5 chars!");
  }

  $('#validationErrors').html("");

  $('#overlay').fadeIn();

  let url = `${URL_PREFIX}/api/createaccount`;
  let recaptcha =  btoa(email);

  $.ajax({
    url : url,
    type : 'POST', 
    data :  {
      "name": fullName,
      "email": email,
      "password": password,
      "manufacturerId": "5c67c495268198273c8551cd",
      "temperatureScale": temperatureScale,
      "language" : "en",
      "timeZone" : timeZone,
      "recaptcha": recaptcha,
      "clientId": 'mobile-app'
    }, 
    success : function(json) {
      $('#overlay').fadeOut();

      if(json.success) {
        showDialog(`Success! We have sent an email to ${email} with a link to activate your account.`);
        $('#createAccountModal').modal('hide');

        // Set the email and password.
        $('#inputSvcEMail').val(email);
        $('#inputSvcPassword').val(password);

      } else {
        $('#validationErrors').html(json.message); 
      }      
    },
    error : function(request, status, error ) {
      console.log("request:", request);
      console.log("status:", status);
      console.log("error:", error);

      $('#overlay').fadeOut();
      showDialog("Error!", error);
    }
  });

}

function setup(productInfo, rooms) {
  _productInfo = productInfo; 

  var devices = _productInfo.devices;  
  var roomSelect = '<select class="form-control" id="selectRoom">';
  roomSelect += $.map(rooms, function (item, a) {
    return "<option value=" + item.id + ">" + item.name + "</option>";
  });
  roomSelect += '</select>';
  
  var templateString = '<div id="devicesWrapper">';
  templateString += `<div class="grid-container">`;

  $.each(devices, function(i) {
    templateString += `<div class="card card-m5px">`;    
    
    templateString += `<div class="card-header">` + productCodeToName(devices[i].code) + `</div>`;
      templateString += `<div class="card-body">`;
        templateString += `<input type="hidden" id="key" name="key" value="${devices[i].name}">`
        templateString += `<input type="hidden" id="productCode" name="productCode" value="${devices[i].code}">`

        templateString += `<div class="form-group">
                            <label for="inputDeviceName">Name <span class="text-danger font-weight-bold">*</span></label>
                            <input id="inputDeviceName" class="form-control" placeholder="Device name" required>
                            <div class="invalid-feedback">Please fill the device name</div>
                          </div>`;    

        templateString += `<div class="form-group">
                    <label for="inputDeviceDescription">Description <span class="text-danger font-weight-bold">*</span></label>
                    <input id="inputDeviceDescription" class="form-control" placeholder="Device description" required>
                    <div class="invalid-feedback">Please fill the device description</div>
                          </div>`;
        
        templateString += `<div class="form-group">
                            <label for="selectRoom">Room <span class="text-danger font-weight-bold">*</span></label>
                            <div class="form-row">
                            ` + roomSelect + `  
                            </div>`;
        
      templateString += `</div>`;
    templateString += `</div>`;
    templateString += `</div>`;
  });

  templateString += `</div>`;
  templateString += `</div>`;

  $('#deviceSetup').append(templateString); 

  enableDisableTab("pills-login", false);
  enableDisableTab("pills-config", true);
  navigateToTab("pills-config");
}
 
function showDialog(title, message) {
  $('#modalTitle').html(title);
  $('#modalBody').html(message);
  $('#myModal').modal('show');
}

function saveConfig() {
  console.log("Configuring device ..");

  var $parent = $('#devicesWrapper').children(":first");
  let devices = [];
  let incomplete = false;

  $parent.children('div').each(function(index,item) {
    let deviceName =  $(this).find('#inputDeviceName').val();
    let deviceDescription = $(this).find('#inputDeviceDescription').val();
    let selectedRoomId = $(this).find('#selectRoom').val();
    let key = $(this).find('#key').val();
    let productCode =  $(this).find('#productCode').val();

    if(deviceName == "") {
      incomplete = true;
    }

    if(deviceDescription == "") {
      incomplete = true;
    }

    if(selectedRoomId == null) {
      incomplete = true;
    }

    devices.push({"name": deviceName, "description" : deviceDescription, "roomId" : selectedRoomId, "key" : key, "productCode" : productCode});
  });

  if(incomplete) {
    return showDialog("Error!", "Please fill the all required fields!");
  }

  let productConfig = {
    "deviceCount" : devices.length,
    "devices" : devices,
  };
 
  const url = `${URL_PREFIX}/api/configure`; 
  $('#overlay').fadeIn();
  
  $.ajax({
    url : url,
    type : 'POST', 
    data :  productConfig, 
    success : function(json) {
      $('#overlay').fadeOut();

      if(json.success) {
        showDialog("Success!", `Success! Device will reboot now.`);
      } else {
        showDialog(json.message); 
      }  
    },
    error : function(request, status, error) {
      console.log("request:", request);
      console.log("status:", status);
      console.log("error:", error);

      $('#overlay').fadeOut();
      showDialog("Error", error);
    }
  });
}

function loadWiFiList() {
  console.log("Loading WiFis ..");
 
  const url = `${URL_PREFIX}/wifi/list`; 
  $('#overlay').fadeIn();

  $.ajax({
    url : url,
    type : 'GET',
    data :  {},
    tryCount : 0,
    retryLimit : 3,
    success : function(json) {
      $('#overlay').fadeOut();

      var options = $("#selectWifiList");      
      $.each(json, function(item) {
          options.append(new Option(this.ssid, this.ssid));
      });
    },
    error : function(request, status, error ) {
      console.log("request:", request);
      console.log("status:", status);
      console.log("error:", error);

      $('#overlay').fadeOut();
      showDialog("Error", error);
    }
  });
}

function configureWiFi(wifiName, password) {
  console.log("Configuring WiFi ..");

  const url = `${URL_PREFIX}/wifi/configure`; 
  $('#overlay').fadeIn();

  $.ajax({
    url : url,
    type : 'POST',
    data :  {
      "ssid": wifiName,
      "pass": password
    }, 
    success : function(json) {
      $('#overlay').fadeOut();

      if(json.success) {
        enableDisableTab("pills-wifi", false);    
        enableDisableTab("pills-login", true);    
        navigateToTab("pills-login");
      } else {
        showDialog("Error", json.message);
      }
    },
    error : function(request, status, error) {
      console.log("request:", request);
      console.log("status:", status);
      console.log("error:", error);

      $('#overlay').fadeOut();
      showDialog("Error", error);
    }
  });
}

function getProductInfo() {
  const url = `${URL_PREFIX}/api/info`;
  return $.ajax({
    crossDomain: true,
    url : url,
    type : 'GET',
  });
}

function getRooms(data, textStatus, jqXHR) {
  const url = `${URL_PREFIX}/api/rooms`;
  return $.ajax({
    crossDomain: true,
    url : url,
    type : 'GET',
  });
}

function authenticate(email, password) {
  console.log("Authenticating user ..");

  const url = `${URL_PREFIX}/api/auth`;
  const token =  btoa(unescape(encodeURIComponent(email+":"+password)));
  const data  = { "token": token };

  $('#overlay').fadeIn();
    
  $.ajax({
    url : url,
    type : 'POST',
    data :  data, 
    crossDomain: true,
    success : function(json) {
      if(json.success) {    
        $.when(
          getProductInfo(),
          getRooms())
          .done(function(productInfoRes, roomRes){
              $('#overlay').fadeOut();

              if(productInfoRes[0] && roomRes[0].success) {
                setup(productInfoRes[0], roomRes[0].rooms); // Setup the device configuration view
                
              } else {
                if(!productInfoRes.success) {
                  showDialog("Error", productInfoRes.message);
                }
                if(!roomRes.success) {
                  showDialog("Error", roomRes.message);
                }
              }
          })
          .fail(function(){
              $('#overlay').fadeOut();
          }); 
      } else {
        $('#overlay').fadeOut(); 
        showDialog("Error", json.message);
      }      
    },
    error : function(request, status, error ) {
      $('#overlay').fadeOut();
      showDialog("Error", error);
    }
  });
}

function selectAutoOrManualSetup(isAuto = true) {
  $("#divAutoSetup").find("*").prop('disabled', !isAuto);
  $("#divManualSetup").find("*").prop('disabled', isAuto);
}

function autoConfigureDevice(email, password) {
  console.log("Auto configure device ..");

  const url = `${URL_PREFIX}/api/autoconfigure`; 
  $('#overlay').fadeIn();

  $.ajax({
    url : url,
    type : 'POST',
    data :  {
      "email": email,
      "password" : password,
      "manufacturerId": "5c67c495268198273c8551cd"
    }, 
    success : function(json) {
      $('#overlay').fadeOut();
      if(json.success) {
        showDialog("Success!", `Success! Device will reboot now.`);
      } else {
        showDialog(json.message); 
      }
    },
    error : function(request, status, error) {
      console.log("request:", request);
      console.log("status:", status);
      console.log("error:", error);

      $('#overlay').fadeOut();
      showDialog("Error", error);
    }
  });
}

document.addEventListener('DOMContentLoaded', function () {
    // Load WiFi list 
    loadWiFiList();

    // Disable login config tabs
    enableDisableTab("pills-login", false);
    enableDisableTab("pills-config", false);    

    $('#btnConnect').on('click', function(event) {
      event.preventDefault();

      var wifiName = $("#selectWifiList").val();
      var wifiPassword = $("#inputWiFiPassword").val();

      if(wifiName == null || wifiName.length == 0) {
        return showDialog("Error", "WiFi name cannot be empty");
      }

      if(wifiPassword.length == 0) {
        return showDialog("Error", "WiFi password cannot be empty");
      }

      configureWiFi(wifiName, wifiPassword);     
    });

  $('#btnRefreshWiFiList').on('click', function(event) {
    event.preventDefault();
    loadWiFiList();
  });

  $('#btnSaveConfig').on('click', function(event) {
    event.preventDefault();
    saveConfig();
  });
 
  $('#btnLogin').on('click', function(event) {
    event.preventDefault();
    var email = $("#inputSvcEMail").val();
    var password = $("#inputSvcPassword").val();

    if(email.length == 0) {
      return showDialog("Error", "Email cannot be empty");
    }

    if(password.length == 0) {
      return showDialog("Error", "Password cannot be empty");
    }

    authenticate(email, password);    
  });

  $("#optManualSetup").on('click', function(event) { 
    selectAutoOrManualSetup(false);
  });

  $("#optAutoSetup").on('click', function(event) { 
    selectAutoOrManualSetup(true);
  });

  // Select Auto by default
  $("input:radio[value='Auto']").prop('checked',true).change();
  selectAutoOrManualSetup(true);

  $('#btnAutoConfigureDevice').on('click', function(event) {
    event.preventDefault();

    var autoConfigureEmail = $("#inputAutoConfigureEmail").val();
    var autoConfigurePassword = $("#inputAutoConfigurePassword").val();
    
    autoConfigureDevice(autoConfigureEmail, autoConfigurePassword);
  });

 
})










