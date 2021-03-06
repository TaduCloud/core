
      <footer class="page-foot col-sm-push-3 col-lg-push-2">
        <div class="container-fluid">
          <a target="_blank" href="<?=$g['product_website']?>" class="redlnk"><?=$g['product_name']?></a> (c)
            <?=$g['product_copyright_years']?> <a href="<?=$g['product_copyright_url']?>" class="tblnk"><?=$g['product_copyright_owner']?></a>
        </div>
      </footer>

  </div>
  <!-- /row-->
</main>

<?php
    if (isset($widgetCollection)):
      // sort by name
      usort($widgetCollection, function ($item1, $item2) {
        return strcmp(strtolower($item1['name']), strtolower($item2['name']));
      });
    ?>
    <div class="modal fade" id="modal_widgets" tabindex="-1" role="dialog" aria-labelledby="modal_widgets_label" aria-hidden="true">
      <div class="modal-dialog">
        <div class="modal-content">
          <div class="modal-header">
              <button type="button" class="close" data-dismiss="modal">
                <span aria-hidden="true">&times;</span>
                <span class="sr-only"><?=gettext("Close");?></span>
              </button>
              <h4 class="modal-title" id="modal_widgets_label"><?=gettext("Available Widgets"); ?></h4>
          </div>
          <div class="modal-body">
              <table class="table table-condensed table-hover">
<?php
          foreach($widgetCollection as $widgetItem):
              $widgettitle = $widgetItem['name'] . "_title";
              $widgettitlelink = $widgetItem['name'] . "_title_link";?>
              <tr id="add_widget_<?=$widgetItem['name']; ?>">
<?php
              if (isset($$widgettitle)):?>
                  <td style="cursor: pointer;" onclick='return addWidget("<?=$widgetItem['name']; ?>")'><?=$$widgettitle; ?></td>
<?php
              elseif (!empty($widgetItem['display_name'])): ?>
                  <td style="cursor: pointer;" onclick='return addWidget("<?=$widgetItem['name']; ?>")'><?=$widgetItem['display_name']; ?></td>
<?php
              endif;?>
              </tr>
<?php
          endforeach; ?>
              </table>
          </div>
          <div class="modal-footer">
              <button type="button" class="btn btn-default" data-dismiss="modal"><?=gettext("Close");?></button>
          </div>
        </div><!-- /modal-content -->
      </div><!-- /modal-dialog -->
    </div><!-- /modal -->
<?php
    endif; ?>

    <!-- bootstrap script -->
    <script type="text/javascript" src="/ui/js/bootstrap.min.js"></script>
    <!-- Fancy select with search options -->
    <script type="text/javascript" src="/ui/js/bootstrap-select.min.js"></script>
    <!-- bootstrap dialog -->
    <script type="text/javascript" src="/ui/js/bootstrap-dialog.min.js"></script>
    <!-- service control hook -->
    <script type="text/javascript">
      $( document ).ready(function() {
        $('.srv_status_act').click(function(event){
          event.preventDefault();
          params = {};
          params['action'] = $(this).data('service_action');
          params['service'] = $(this).data('service');
          params['id'] = $(this).data('service_id');
          $.post('/status_services.php',params, function(data) {
            // refresh page after service action via server
            location.reload(true);
          });
        });
      });
    </script>
  </body>
</html>
