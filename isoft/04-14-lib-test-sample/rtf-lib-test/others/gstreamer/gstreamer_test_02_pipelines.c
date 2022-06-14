#include <gst/gst.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXPATH 1024

int
main (int argc, char *argv[])
{
  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;

  char buffer[MAXPATH];
  char path[MAXPATH]="playbin uri=file://";
  getcwd(buffer,MAXPATH);
  strcat(path, buffer);
  strcat(path, "/libcfg/gstreamer/sintel_trailer-480p.webm");
  printf("%s\n",path);

  /* Initialize GStreamer */
  gst_init (&argc, &argv);

  /* Build the pipeline */
  pipeline =
      gst_parse_launch
      (path, NULL);

  /* Start playing */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline);
  msg =
      gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
      GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* Free resources */
  if (msg != NULL)
    gst_message_unref (msg);
  gst_object_unref (bus);
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);
  return 0;
}
