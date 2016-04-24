angular.module('starter.controllers', [])
.constant('FORECASTIO_KEY', 'cd9e0bf195c881329d9b49ff34de8224')
.controller('DashCtrl', function($scope) {})

.controller('ChatsCtrl', function($scope, Chats) {
  // With the new view caching in Ionic, Controllers are only called
  // when they are recreated or on app start, instead of every page change.
  // To listen for when this page is active (for example, to refresh data),
  // listen for the $ionicView.enter event:
  //
  //$scope.$on('$ionicView.enter', function(e) {
  //});

  $scope.chats = Chats.all();
  $scope.remove = function(chat) {
    Chats.remove(chat);
  };
})

.controller('ChatDetailCtrl', function($scope, $stateParams, Chats) {
  $scope.chat = Chats.get($stateParams.chatId);
})

.controller('AccountCtrl', function($scope,$state,Weather,Cities) {
  $scope.cities = Cities.all();
  $scope.temperature = "0";
  $scope.summary = "No definido";
  $scope.windSpeed = "0";

  $scope.changeCity = function(cityId) {
    //get lat and longitude for seleted location
    var lat  = $scope.cities[cityId].lat; //latitude
    var lgn  = $scope.cities[cityId].lgn; //longitude
    var city = $scope.cities[cityId].name; //city name
    Weather.getCurrentWeather(lat,lgn).then(function(resp) {
      $scope.temperature = resp.data.currently.apparentTemperature;
      $scope.summary = resp.data.currently.summary;
      $scope.windSpeed = resp.data.currently.windSpeed;
    }, function(error) {
      alert('Unable to get current conditions');
      console.error(error);
    });
  	//$state.go('tab.home');
  }
});
