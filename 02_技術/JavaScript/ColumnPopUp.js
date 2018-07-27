function pageLoad(sender, args) {
	$('td[class^="col-"]').on({
		'mouseenter': function (ev) {
			var top = $(this).position().top;
			var left = $(this).position().left;
			top = Math.floor(top);
			left = Math.floor(left);
			var text = $(this).children("span").attr('id');
			$("body").append('<div id="tooltip" class="columnTooltip">' + text + '</div>');
			var obj = $("#tooltip");
			var x = ev.pageX;
			var y = ev.pageY;
			obj.css({ top: y, left: x + 10, display: "block" });
		},
		'mousemove': function (ev) {
			var top = $(this).position().top;
			var left = $(this).position().left;
			top = Math.floor(top);
			left = Math.floor(left);
			var obj = $("#tooltip");
			var x = ev.pageX;
			var y = ev.pageY;
			obj.css({ top: y + 34, left: x + 14 });
		},
		'mouseleave': function () {
			var top = $(this).position().top;
			var left = $(this).position().left;
			top = Math.floor(top);
			left = Math.floor(left);
			$("#tooltip").remove()
		}
	})
}

