window.BENCHMARK_DATA = {
  "lastUpdate": 1765708811037,
  "repoUrl": "https://github.com/GuntramStrecha/zip_view",
  "entries": {
    "C++ Benchmark": [
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "0da400dc7dae9a77d4758064ae1bb669d096408c",
          "message": "fixup! Add benchmarks to github actions",
          "timestamp": "2025-12-11T17:55:34+01:00",
          "tree_id": "b7283276692604ec67c793bcbbef41df30ad78aa",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/0da400dc7dae9a77d4758064ae1bb669d096408c"
        },
        "date": 1765472261786,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 138.197,
            "range": "± 23.5564",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 138.731,
            "range": "± 22.4183",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 578.167,
            "range": "± 60.8681",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 566.845,
            "range": "± 73.5245",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 144.633,
            "range": "± 19.8292",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 151.628,
            "range": "± 21.8796",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 157.512,
            "range": "± 20.5731",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 141.232,
            "range": "± 22.9613",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "bc7b11b7c8f86970b5043b73a0f358b85fc4f256",
          "message": "Simplify min_size function to avoid min_value templates",
          "timestamp": "2025-12-11T18:02:25+01:00",
          "tree_id": "eee1611d6cee63bcabc34085c248e2d21006f370",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/bc7b11b7c8f86970b5043b73a0f358b85fc4f256"
        },
        "date": 1765472679126,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 92.4671,
            "range": "± 22.2665",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 96.9448,
            "range": "± 22.8182",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 293.24,
            "range": "± 47.6786",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 291.55,
            "range": "± 42.1359",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 88.5148,
            "range": "± 25.4407",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 87.5244,
            "range": "± 24.8601",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 161.152,
            "range": "± 11.3001",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 92.7358,
            "range": "± 23.4595",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "1bf0ff46335b7edf5831c5a4dacc1d0219cf9891",
          "message": "Simplify min_size function to avoid min_value templates",
          "timestamp": "2025-12-11T18:08:55+01:00",
          "tree_id": "deaf1246494438052e9278b4f6aac87d4a39f87e",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/1bf0ff46335b7edf5831c5a4dacc1d0219cf9891"
        },
        "date": 1765473073042,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 85.2467,
            "range": "± 19.3727",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 92.6999,
            "range": "± 19.5604",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 249.082,
            "range": "± 67.8187",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 245.502,
            "range": "± 63.6921",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 75.7541,
            "range": "± 13.6048",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 79.0529,
            "range": "± 18.4913",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 161.596,
            "range": "± 20.1678",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 88.5161,
            "range": "± 20.2074",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "17ef4919454f03d574cceb58d6c3de4d61b45a2c",
          "message": "Simplify min_size function to avoid min_value templates",
          "timestamp": "2025-12-11T18:16:46+01:00",
          "tree_id": "811215706a5cd6ed7616d0e5151c937ccabb4930",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/17ef4919454f03d574cceb58d6c3de4d61b45a2c"
        },
        "date": 1765473780096,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 89.3225,
            "range": "± 25.621",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 85.7561,
            "range": "± 17.0555",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 249.608,
            "range": "± 63.5858",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 242.685,
            "range": "± 66.1053",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 79.0062,
            "range": "± 28.7912",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 78.2026,
            "range": "± 26.9368",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 164.021,
            "range": "± 23.5795",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 87.436,
            "range": "± 20.9622",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "69329ba0d7f8011aa9c860bb35192b7723ccd1f0",
          "message": "Remove unused includes",
          "timestamp": "2025-12-11T18:34:35+01:00",
          "tree_id": "88878ea20431142484f39d0371696e9d1933c25d",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/69329ba0d7f8011aa9c860bb35192b7723ccd1f0"
        },
        "date": 1765474607673,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 91.7368,
            "range": "± 17.9258",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 92.8463,
            "range": "± 19.9433",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 232.383,
            "range": "± 59.3155",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 245.737,
            "range": "± 63.4142",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 79.9591,
            "range": "± 19.5678",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 85.3944,
            "range": "± 15.043",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 159.682,
            "range": "± 10.6062",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 88.4868,
            "range": "± 17.8983",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "ba98a53b364babe6fd5564f0c27f70c1d3b4b90a",
          "message": "Remove unused includes",
          "timestamp": "2025-12-11T18:38:41+01:00",
          "tree_id": "767a7cb17c98331abf40c57a020b42b98a3c0dfa",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/ba98a53b364babe6fd5564f0c27f70c1d3b4b90a"
        },
        "date": 1765474878727,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 88.253,
            "range": "± 17.977",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 92.9015,
            "range": "± 15.3555",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 226.277,
            "range": "± 48.5721",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 214.196,
            "range": "± 45.4691",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 73.5107,
            "range": "± 28.0321",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 79.074,
            "range": "± 18.1219",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 158.8,
            "range": "± 9.82237",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 88.7742,
            "range": "± 20.0029",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "322e7a256e41eb4c1bfd852c5b783961de4eae58",
          "message": "Fix benchmark descriptions",
          "timestamp": "2025-12-11T22:35:31+01:00",
          "tree_id": "a07b063cd6b2b294c3abb763a5309140044c8277",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/322e7a256e41eb4c1bfd852c5b783961de4eae58"
        },
        "date": 1765489053496,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 84.9695,
            "range": "± 13.1562",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 84.7066,
            "range": "± 12.3408",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 277.568,
            "range": "± 27.3677",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 274.965,
            "range": "± 30.0302",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 81.8365,
            "range": "± 15.9098",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 81.8277,
            "range": "± 23.6342",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 83.0546,
            "range": "± 11.5848",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 84.2038,
            "range": "± 11.2162",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "fdf9b04f38cf913c9c4fc993376eb9532d1fc68d",
          "message": "Enhance compiler options",
          "timestamp": "2025-12-11T23:48:40+01:00",
          "tree_id": "775e96131a8f95f5a75e42d9ef11f7c800514c08",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/fdf9b04f38cf913c9c4fc993376eb9532d1fc68d"
        },
        "date": 1765493440531,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 81.905,
            "range": "± 8.7187",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 84.0014,
            "range": "± 12.6373",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 222.546,
            "range": "± 36.5604",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 224.336,
            "range": "± 37.5901",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 69.6078,
            "range": "± 6.40965",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 69.2402,
            "range": "± 6.49256",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 81.8803,
            "range": "± 6.81124",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 81.7644,
            "range": "± 8.52035",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "0880a637915a95ed4bfe3569fc75e5740edc041c",
          "message": "Enhance unit test",
          "timestamp": "2025-12-11T23:57:55+01:00",
          "tree_id": "f6e12f57c2681b6161c0d26a549dad70f84817ae",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/0880a637915a95ed4bfe3569fc75e5740edc041c"
        },
        "date": 1765494009720,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 86.7553,
            "range": "± 20.9074",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 88.3961,
            "range": "± 19.6313",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 289.746,
            "range": "± 36.7385",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 292.859,
            "range": "± 27.8034",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 87.1478,
            "range": "± 26.0583",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 93.7625,
            "range": "± 27.0188",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 91.6842,
            "range": "± 18.3706",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 90.554,
            "range": "± 19.5833",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "42fbbfa30d705ddb4236baefc0db839f552e1246",
          "message": "Add adaptive iterator category to zip_view\n\nThe iterator category now adapts to the weakest underlying range:\n- Random access when all ranges are random-access\n- Bidirectional when all ranges are at least bidirectional\n- Forward when any range is only forward\n\nThis enables algorithms like std::sort to work directly on zip_view\nwhen all underlying ranges support random access.",
          "timestamp": "2025-12-12T00:08:23+01:00",
          "tree_id": "cc0a5b88789ee3312856f09898e7731c43470490",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/42fbbfa30d705ddb4236baefc0db839f552e1246"
        },
        "date": 1765494630916,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 97.5906,
            "range": "± 22.4508",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 85.9601,
            "range": "± 18.7549",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 287.981,
            "range": "± 48.2012",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 279.408,
            "range": "± 54.8937",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 88.172,
            "range": "± 26.9965",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 90.7528,
            "range": "± 22.6805",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 99.9874,
            "range": "± 24.062",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 94.1536,
            "range": "± 17.813",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "0bfa2c9fa5b6d2ecaea68ac5371a0ea5c791f546",
          "message": "Add tests for iterator category adaptation\n\nTests verify that zip_view correctly adapts its iterator category\nbased on the weakest underlying container type.",
          "timestamp": "2025-12-14T11:12:27+01:00",
          "tree_id": "0779de933bd8b8111d50d1438c8d02f5a649c952",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/0bfa2c9fa5b6d2ecaea68ac5371a0ea5c791f546"
        },
        "date": 1765707338337,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 89.3398,
            "range": "± 13.0027",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 85.6597,
            "range": "± 13.9776",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 282.199,
            "range": "± 31.1104",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 276.786,
            "range": "± 28.0528",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 84.9367,
            "range": "± 25.7337",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 81.8376,
            "range": "± 18.4924",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 82.6584,
            "range": "± 13.6449",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 86.6941,
            "range": "± 18.1629",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "f29bbc7384c5dcfa6bda014ae2a1f6d6e9604378",
          "message": "Add comprehensive STL algorithm tests for zip_view\n\nAdd extensive test coverage for standard algorithms including:\n- Sorting algorithms (sort, stable_sort, partial_sort, nth_element)\n- Searching algorithms (find, find_if, binary_search, etc.)\n- Partitioning algorithms (partition, stable_partition)\n- Modifying algorithms (reverse, rotate, replace, unique)\n- Non-modifying algorithms (all_of, any_of, none_of, equal, mismatch)\n- Min/max algorithms (min_element, max_element, minmax_element)\n- Permutation algorithms (next_permutation, prev_permutation)\n\nThese tests demonstrate that zip_view works correctly with standard\nalgorithms when the iterator category requirements are met.",
          "timestamp": "2025-12-14T11:24:10+01:00",
          "tree_id": "9bbfa729ab9b48740b71e1f942c0023b00351f6e",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/f29bbc7384c5dcfa6bda014ae2a1f6d6e9604378"
        },
        "date": 1765707975160,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 84.0294,
            "range": "± 13.3817",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 87.3403,
            "range": "± 13.7544",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 220.402,
            "range": "± 44.1256",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 220.167,
            "range": "± 42.4557",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 68.7985,
            "range": "± 21.7977",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 67.6957,
            "range": "± 17.7973",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 84.5977,
            "range": "± 13.4403",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 83.6027,
            "range": "± 15.9517",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "2d71b1ddef63dc5c832d6a57d6afc5bfb0ca7409",
          "message": "Update README with examples and iterator category docs\n\n- Reorganize examples section with multiple use cases\n- Add example showing std::sort with zip_view\n- Document iterator category adaptation behavior\n- Add note about algorithm compatibility based on iterator type",
          "timestamp": "2025-12-14T11:33:04+01:00",
          "tree_id": "97a9cc8e18275a508a6af5d6732d7861881425c1",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/2d71b1ddef63dc5c832d6a57d6afc5bfb0ca7409"
        },
        "date": 1765708501413,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 95.2869,
            "range": "± 15.5449",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 93.0531,
            "range": "± 21.2359",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 286.48,
            "range": "± 32.3732",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 300.59,
            "range": "± 40.8773",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 73.5488,
            "range": "± 9.14373",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 78.0888,
            "range": "± 12.3133",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 85.6946,
            "range": "± 17.496",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 85.4815,
            "range": "± 16.2069",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "7f8a9106e09b755a2ecb6188589b4fa10d398386",
          "message": "Reorder algorithm tests",
          "timestamp": "2025-12-14T11:38:02+01:00",
          "tree_id": "9be3611c7fe589f91076c558d2547a85a759a165",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/7f8a9106e09b755a2ecb6188589b4fa10d398386"
        },
        "date": 1765708810650,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 97.0819,
            "range": "± 23.6843",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 102.175,
            "range": "± 26.4734",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 295.55,
            "range": "± 54.2157",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 299.625,
            "range": "± 50.1418",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 86.2069,
            "range": "± 25.0828",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 102.9,
            "range": "± 26.3517",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 101.803,
            "range": "± 28.2004",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 104.497,
            "range": "± 23.4451",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}